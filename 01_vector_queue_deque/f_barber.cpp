#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> data(n);
    int l = 0, r = 0;

    int hh, mm, rate;
    while(n--) {
        cin >> hh >> mm >> rate;
        mm += hh * 60;
        for (int i = l; i < r; i++) {
            if (data[i] <= mm) {
                l = i + 1;
            }
        }
        if (rate < r - l) {
            cout << mm / 60 << ' ' << mm % 60 << '\n';
        } else if (l == r || data[r - 1] < mm) {
            data[r++] = mm + 20;
            cout << data[r - 1] / 60 << ' ' << data[r - 1] % 60 << '\n';
        } else {
            data[r++] = data[r - 1] + 20;
            cout << data[r - 1] / 60 << ' ' << data[r - 1] % 60 << '\n';
        }
    }
}
