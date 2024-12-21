#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, s, f;
    cin >> n >> s >> f;
    s--;
    f--;

    vector<vector<int>> g(n, vector<int>(n));
    int next;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> g[i][j];
        }
    }

    vector<bool> visited(n);
    vector<int> paths(n);
    for (int i = 0; i < n; ++i) {
        paths[i] = 1001;
        visited[i] = false;
    }
    priority_queue<pair<int, int>> next_paths;

    paths[s] = 0;
    next_paths.push({paths[s], s});
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
        for (int i = 0; i < g[cur.second].size(); ++i) {
            if (g[cur.second][i] > -1) {
                next_paths.push({paths[cur.second] + g[cur.second][i], i});
            }
        }
        visited[cur.second] = true;
    } while (!next_paths.empty());

    cout << paths[f];
}