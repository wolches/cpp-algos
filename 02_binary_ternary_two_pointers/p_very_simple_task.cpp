#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x, y;
    cin >> n >> x >> y;

    int initial = x < y ? x : y;
    n--;

    int l = 0, r = 1e9, m, xm, ym;
    while (l < r) {
        m = l + ((r - l) / 2);
        xm = m / x;
        ym = m / y;
        if (xm + ym < n) {
            l = m + 1;
        } else {
            r = m;
        }
    }

    cout << initial + l;
}

