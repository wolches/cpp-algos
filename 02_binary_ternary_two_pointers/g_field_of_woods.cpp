#include <bits/stdc++.h>

using namespace std;

double vp, vf, a;

double len(double x, double y) {
    return sqrt((x * x) + (y * y));
}

double calcTime(double x) {
    return (len(x, 1.0 - a) / vp) + (len(1.0 - x, a) / vf);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> vp >> vf >> a;

    double l = 0.0, r = 1.0, e = 1e-9, m1, m2;
    while (r - l > e) {
        m1 = l + ((r - l) / 3);
        m2 = r - ((r - l) / 3);
        if (calcTime(m1) > calcTime(m2)) {
            l = m1;
        } else {
            r = m2;
        }
    }

    cout << fixed << setprecision(9) << l;
}