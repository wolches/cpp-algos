#include <bits/stdc++.h>

using namespace std;

int main() { // TODO
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    unsigned long long w, h, n;
    cin >> n >> w >> h;

    unsigned long long l = 0, r = (w > h ? w : h) * n, m;
    while (l < r) {
        m = ((r - l) / 2) + l;
        unsigned long long hCount = m / h;
        unsigned long long wCount = m / w;
        unsigned long long rem = n % wCount;

        if (n / wCount >= hCount - rem) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    cout << l;
}

