#include <bits/stdc++.h>

using namespace std;

struct p {
    int a, b, c;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<p> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i].a >> p[i].b >> p[i].c;
    }

    vector<int> dp(n);

    int a, b, c;
    for (int i = 0; i < n; ++i) {
        a = p[i].a + (i == 0 ? 0 : dp[i - 1]);
        if (i > 1) {
           b = p[i - 1].b + dp[i - 2];
           c = p[i - 2].c + (i == 2 ? 0 : dp[i - 3]);
           dp[i] = min(min(a, b), c);
        } else if (i > 0) {
           b = p[i - 1].b + dp[i - 2];
           dp[i] = min(a, b);
        } else {
           dp[i] = a;
        }
    }

    cout << dp[n - 1];
}