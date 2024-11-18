#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g;
vector<char> used;
vector<int> topsort;

bool dfs(int v) {
    if (used[v] == 1) {
        return false;
    } else if (used[v] == 2) {
        return true;
    } else {
        used[v] = 1;
        for (const auto &u: g[v]) {
            if (!dfs(u)) {
                return false;
            }
        }
        used[v] = 2;
        topsort.push_back(v);
        return true;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    g.assign(n, vector<int>());
    used.assign(n, 0);
    topsort.assign(0, -1);
    int u, v;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
    }
    bool canSort = true;
    for (int i = 0; i < n; ++i) {
        if (!dfs(i)) {
            canSort = false;
            break;
        }
    }
    if (canSort) {
        std::reverse(topsort.begin(), topsort.end());
        for (const auto &item: topsort) {
            cout << item + 1 << ' ';
        }
    } else {
        cout << -1;
    }
}