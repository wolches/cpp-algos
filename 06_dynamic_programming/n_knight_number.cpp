#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 0 -> 4, 6
    // 1 -> 6, 8
    // 2 -> 7, 9
    // 3 -> 4, 8
    // 4 -> 3, 9, 0
    // 5 -> -
    // 6 -> 1, 7, 0
    // 7 -> 2, 6
    // 8 -> 1, 3
    // 9 -> 2, 4

    int mod = 1'000'000'000;
    int n;
    cin >> n;

    vector<vector<int>> dp(10, vector<int>(n + 1));
    for (int i = 0; i < 10; ++i) {
        if (i != 0 && i != 8) {
            dp[i][1] = 1;
        }
    }
    for (int i = 2; i <= n; ++i) {
        dp[0][i] = ((dp[4][i - 1] % mod) + (dp[6][i - 1] % mod)) % mod;
        dp[1][i] = ((dp[6][i - 1] % mod) + (dp[8][i - 1] % mod)) % mod ;
        dp[2][i] = ((dp[7][i - 1] % mod) + (dp[9][i - 1] % mod)) % mod;
        dp[3][i] = ((dp[4][i - 1] % mod) + (dp[8][i - 1] % mod)) % mod;
        dp[4][i] = ((dp[3][i - 1] % mod) + (dp[9][i - 1] % mod) + (dp[0][i - 1] % mod)) % mod;
        dp[5][i] = 0;
        dp[6][i] = ((dp[1][i - 1] % mod) + (dp[7][i - 1] % mod) + (dp[0][i - 1] % mod)) % mod;
        dp[7][i] = ((dp[2][i - 1] % mod) + (dp[6][i - 1] % mod)) % mod;
        dp[8][i] = ((dp[1][i - 1] % mod) + (dp[3][i - 1] % mod)) % mod;
        dp[9][i] = ((dp[2][i - 1] % mod) + (dp[4][i - 1] % mod)) % mod;
    }

    int ans = 0;
    for (int i = 0; i < 10; ++i) {
        ans += dp[i][n] % mod;
    }

    cout << ans;
}