#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> ladder(n);
    for (int i = 0; i < n; ++i) {
        cin >> ladder[i];
    }

    vector<int> dp(n);
    dp[0] = ladder[0];

    if (n > 1) {
        dp[1] = ladder[1] + max(dp[0], 0);
        for (int i = 2; i < n; ++i) {
            dp[i] = ladder[i] + max(dp[i - 1], dp[i - 2]);
        }
    }

    cout << dp[n - 1];
}
