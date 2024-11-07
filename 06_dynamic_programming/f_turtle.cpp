#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> field(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> field[i][j];
        }
    }

    vector<vector<int>> dp(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            dp[i][j] = field[i][j];
            if (i == 0 && j == 0) {
                continue;
            }
            int left = j == 0 ? 251'000'000 : dp[i][j - 1];
            int up = i == 0 ? 251'000'000 : dp[i - 1][j];
            dp[i][j] += min(left, up);
        }
    }
    cout << dp[n - 1][m - 1];
}