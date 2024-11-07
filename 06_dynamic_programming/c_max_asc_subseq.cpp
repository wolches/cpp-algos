#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> data(n);

    for (int i = 0; i < n; ++i) {
        cin >> data[i];
    }

    vector<int> dp(n);
    vector<int> last(n);
    dp[0] = 1;
    last[0] = -1;

    int next, maxIdx = 0;
    for (int i = 1; i < n; ++i) {
        dp[i] = 1;
        for (int j = 1; j <= i; ++j) {
            next = i - j;
            if (data[next] < data[i]) {
                if (dp[i] < dp[next] + 1) {
                    dp[i] = dp[next] + 1;
                    last[i] = next;
                }
            }
        }
        if (dp[i] > dp[maxIdx]) {
            maxIdx = i;
        }
    }

    cout << dp[maxIdx] << '\n';

    vector<int> ans;
    while (maxIdx != -1) {
        ans.push_back(data[maxIdx]);
        maxIdx = last[maxIdx];
    }

    std::reverse(ans.begin(), ans.end());
    for (const auto &item: ans) {
        cout << item << ' ';
    }
}
