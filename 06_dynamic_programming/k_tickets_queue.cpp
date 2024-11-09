#include <bits/stdc++.h>

using namespace std;

struct p {
    int a, b, c, dp;
    char type = 'a';
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

    for (int i = 0; i < n; ++i) {
        p[i].dp = p[i].a;
        if (i > 0) {
            if (p[i - 1].b < (p[i - 1].dp + p[i].dp) && p[i - 1].dp > 0) {
                p[i - 1].dp = p[i - 1].b;
                p[i].dp = 0;
            }
        }
        if (i > 1) {
            if (p[i - 2].c < (p[i - 2].dp + p[i - 1].dp + p[i].dp) && p[i - 2].dp > 0) {
                p[i - 2].dp = p[i - 2].c;
                p[i - 1].dp = 1;
                p[i].dp = 0;
            }
        }
    }

    int ans = 0;
    for (const auto &item: p) {
        ans += item.dp;
    }

    cout << ans;
}