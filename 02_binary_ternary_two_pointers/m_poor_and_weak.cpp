#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> sum_a(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (i != 0) {
            sum_a[i] = sum_a[i - 1] + a[i];
        } else {
            sum_a[i] = a[i];
        }
    }

    double l = -1e4, r = 1e4, m1, m2, e = 1e-9;
    while (r - l > e) {
        // TODO
    }
}