#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;
    x--;

    vector<vector<int>> g(n, vector<int>());
    int next;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> next;
            if (next == 1) {
                g[i].push_back(j);
            }
        }
    }

    vector<bool> visited(n);
    vector<int> paths(n);
    for (int i = 0; i < n; ++i) {
        paths[i] = 1001;
        visited[i] = false;
    }
    priority_queue<pair<int, int>> next_paths;

    paths[x] = 0;
    next_paths.push({paths[x], x});
    do {
        pair<int, int> cur = next_paths.top();
        next_paths.pop();
        if (cur.first < paths[cur.second]) {
            paths[cur.second] = cur.first;
            if (visited[cur.second]) {
                visited[cur.second] = false;
            }
        }
        if (visited[cur.second]) {
            continue;
        }
        for (const auto &item: g[cur.second]) {
            next_paths.push({paths[cur.second] + 1, item});
        }
        visited[cur.second] = true;
    } while (!next_paths.empty());

    for (int i = 0; i < n; ++i) {
        cout << (paths[i] == 1001 ? -1 : paths[i]) << ' ';
    }
}