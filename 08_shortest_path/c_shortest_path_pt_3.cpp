#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n, vector<int>(n, -1));
    int u, v, c;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v >> c;
        g[--u][--v] = c;
    }

    vector<bool> visited(n);
    vector<int> paths(n);
    for (int i = 0; i < n; ++i) {
        paths[i] = -1;
        visited[i] = false;
    }
    priority_queue<pair<int, int>> next_paths;

    paths[0] = 0;
    next_paths.push({paths[0], 0});
    do {
        pair<int, int> cur = next_paths.top();
        next_paths.pop();
        if (cur.first < paths[cur.second] || paths[cur.second] == -1) {
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

    for (const auto &item: paths) {
        cout << item << ' ';
    }
}