#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, l, r;
    cin >> n >> k >> l >> r;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    multimap<int, int> res;
    for (int i = 0; i < n - k; ++i) {
        for (int j = i + 1; j < i + k; ++j) {
            int diff = abs(a[j] - a[i]);
            int reverseDiff = abs(a[i] - a[j]);
            if (
                    (diff >= l && diff <= r)
                    || ((reverseDiff >= l && reverseDiff <= r))
            ) {
                res.insert({i, j});
            }
        }
    }

    if (res.size() > 0) {
        auto first = res.begin();
        cout << first->first << ' ' << first->second;
    } else {
        cout << -1 << ' ' << -1;
    }
}