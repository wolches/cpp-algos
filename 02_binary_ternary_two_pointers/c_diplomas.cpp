#include <bits/stdc++.h>

using namespace std;

int main() { // TODO
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    unsigned long long w, h, n;
    cin >> n >> w >> h;

    unsigned long long l = 0, r = (w > h ? w : h) * n, m, hCount, wCount;
    while (l < r) {
        m = ((r - l) / 2) + l;
        hCount = m / h;
        wCount = m / w;

        if (hCount == 0 || wCount < ((n + hCount - 1) / hCount)) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    hCount = (l - 1) / h;
    wCount = (l - 1) / w;
    bool decrement = (hCount > 1) && (wCount < ((n + hCount - 1) / hCount));
    cout << (decrement ? l : l - 1);
}

