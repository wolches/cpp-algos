#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<int, int>> g;
vector<int> dp;
vector<char> used;

bool dfs(int v) {
    if (used[v]) {
        return false;
    }
    // TODO
    used[v] = 1;
    for (const auto &u: g[v]) {
        dfs(u);
    }
    used[v] = 2;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, s, t;
    cin >> n >> m >> s >> t;
    g.assign(n, vector<pair<int, int>>());
    used.assign(n, 0);
    int u, v, w;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        u--;
        v--;
        g[u].push_back({v, w});
    }

    // TODO
}