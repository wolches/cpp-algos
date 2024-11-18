#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g;
vector<char> used;
int curComp = 0;
vector<int> comp;

bool dfs(int v) {
    if (used[v]) {
        return false;
    }
    used[v] = 1;
    comp[v] = curComp;
    for (const auto &u: g[v]) {
        dfs(u);
    }
    used[v] = 2;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    g.assign(n, vector<int>());
    used.assign(n, 0);
    comp.assign(n, -1);
    int u, v;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 0; i < n; ++i) {
        if (dfs(i)) {
            ++curComp;
        }
    }
    cout << curComp << '\n';
    for (const auto &item: comp) {
        cout << item + 1 << ' ';
    }
}