#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> dp(n);
    dp[0] = 1;

    for (int i = 1; i < n; ++i) {
        int ways = min(i, k);
        for (int j = ways; j > 0; --j) {
            dp[i] += dp[i - j];
        }
    }

    cout << dp[n - 1];
}
