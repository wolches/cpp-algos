#include <bits/stdc++.h>
#define int long long

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> dp(n + 1);
    dp[0] = 0;
    for (int i = 1; i < n; ++i) {
        int i1 = i + 1, i2 = i * 2, i3 = i * 3;
        if (dp[i1]) {
            dp[i1] = dp[i1];
        } else {
            dp[i1] = i;
        }
        if (dp[i2]) {
            dp[i2] = dp[i2];
        } else {
            dp[i2] = i;
        }
        if (dp[i3]) {
            dp[i3] = dp[i3];
        } else {
            dp[i3] = i;
        }
    }

    int next = n;
    stack<int> ans;
    while (next) {
        ans.push(next);
        next = dp[next];
    }
    cout << ans.size() << '\n';
    while (!ans.empty()) {
        cout << ans.top() << ' ';
        ans.pop();
    }
}