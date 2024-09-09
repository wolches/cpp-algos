#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("che.in", "r", stdin);
    freopen("che.out", "w", stdout);

    int n, r;
    cin >> n >> r;

    vector<int> data(n);

    for (int i = 0; i < n; ++i) {
        cin >> data[i];
    }

    int m = 0, k = 0;
    long long c = 0;
    while (k < n) {
        if (data[k] - data[m] > r) {
            c += n - k;
            m++;
        } else {
            k++;
        }
    }

    cout << c;
}