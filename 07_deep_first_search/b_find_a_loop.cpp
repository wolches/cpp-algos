#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g;
vector<char> used;
vector<int> loop;

bool dfs(int v) {
    if (used[v] == 2) {
        return false;
    } else if (used[v] == 1) {
        loop.push_back(v);
        return true;
    }
    used[v] = 1;
    loop.push_back(v);
    for (const auto &u: g[v]) {
        if (dfs(u)) {
            return true;
        }
    }
    used[v] = 2;
    loop.pop_back();
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    g.assign(n, vector<int>());
    used.assign(n, 0);
    int u, v;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
    }
    bool hasLoop = false;
    for (int i = 0; i < n; ++i) {
        if (dfs(i)) {
            hasLoop = true;
            break;
        }
    }
    if (hasLoop) {
        while (loop.front() != loop.back()) {
            loop.erase(loop.begin());
        }
        loop.pop_back();
    }
    cout << (hasLoop ? "YES" : "NO") << '\n';
    for (const auto &item: loop) {
        cout << item + 1 << ' ';
    }
}