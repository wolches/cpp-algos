#include <bits/stdc++.h>

using namespace std;

double calculate(double x) {
    return (x * x) + sqrt(x);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    double c;
    cin >> c;

    double l = 0.0, r = 1e9, e = 1e-9, m;
    while (r - l > e) {
        m = (l + r) / 2;
        if (calculate(m) < c) {
            l = m;
        } else {
            r = m;
        }
    }

    cout << fixed << setprecision(9) << l;
}

