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

    for (int i = 0; i < n - k; ++i) {
        for (int j = i + 1; j < n && j <= i + k; ++j) {
            int diff = abs(a[j] - a[i]);
            if (diff >= l && diff <= r) {
                cout << i << ' ' << j;
                return 0;
            }
        }
    }

    cout << -1 << ' ' << -1;
}