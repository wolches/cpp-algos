#include <bits/stdc++.h>

using namespace std;

struct dp_t {
    int left, up, dp;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    vector<vector<dp_t>> dp(n, vector<dp_t>(m, {0,0,0}));
    int max_dp = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            dp[i][j].left = a[i][j] * (i > 0 ? (dp[i - 1][j].left + 1) : 1);
            dp[i][j].up = a[i][j] * (j > 0 ? (dp[i][j - 1].up + 1) : 1);
            if (i > 0 && j > 0) {
                int size = min(dp[i][j].left, dp[i][j].up);
                if (dp[i - 1][j - 1].dp < size) {
                    dp[i][j].dp = dp[i - 1][j - 1].dp + 1;
                } else {
                    dp[i][j].dp = size;
                }
            } else {
                dp[i][j].dp = a[i][j];
            }
            max_dp = max(dp[i][j].dp, max_dp);
        }
    }

    cout << max_dp;
}