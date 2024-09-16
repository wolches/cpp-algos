#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n;

    vector<double> data(n);
    for (int i = 0; i < n; ++i) {
        cin >> data[i];
    }

    cin >> q;
    int l, r, x;
    for (int i = 0; i < q; ++i) {
        cin >> l >> r >> x;
        bool has = false;
        for (int j = l - 1; j < r; ++j) { // O (N ^ 2)
            if (data[j] == x) {
                has = true;
                break;
            }
        }
        cout << (has ? 1 : 0);
    }
}