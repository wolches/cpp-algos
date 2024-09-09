#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> data(n);
    for (int i = 0; i < n; ++i) {
        cin >> data[i];
    }
    int cur, l, r, m;
    for (int i = 0; i < k; ++i) {
        cin >> cur;
        l = 0;
        r = n;
        while (l < r) {
            m = (l + r) / 2;
            if (data[m] < cur) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        cout << (cur == data[l] ? "YES" : "NO") << '\n';
    }
}

