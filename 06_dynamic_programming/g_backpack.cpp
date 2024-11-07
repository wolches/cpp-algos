#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int s, n;
    cin >> s >> n;
    vector<int> a(n + 1);
    for (int i = 1; i < n + 1; ++i) {
        cin >> a[i];
    }
    std::sort(a.begin(), a.end());
    int end = *std::lower_bound(a.begin(), a.end(), s);

    vector<vector<bool>> dp(end + 1, vector<bool>(s + 1));
    for (int i = 0; i < s + 1; ++i) {
        dp[0][i] = true;
    }
    int max_j = 0;
    for (int i = 1; i <= end; ++i) {
        for (int j = 1; j <= s; ++j) {
            dp[i][j] = dp[i - 1][j] || (j - a[i] >= 0 && dp[i - 1][j - a[i]]);
            if (dp[i][j] && j > max_j) {
                max_j = j;
            }
        }
    }

    cout << max_j;
}