#include <bits/stdc++.h>

using namespace std;

double len(double start, double target) {
    return abs(start - target);
}

double calcTimeSingle(double start, double target, double v) {
    return len(start, target) / v;
}

double calcMaxTime(const vector<pair<double, double>>& xv, double target) {
    double maxTime, cur;
    for (int i = 0; i < xv.size(); ++i) {
        cur = calcTimeSingle(xv[i].first, target, xv[i].second);
        if (i == 0) {
            maxTime = cur;
        } else {
            maxTime = max(maxTime, cur);
        }
    }
    return maxTime;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<double, double>> data(n);

    for (int i = 0; i < n; ++i) {
        cin >> data[i].first;
    }
    for (int i = 0; i < n; ++i) {
        cin >> data[i].second;
    }
    std::sort(data.begin(), data.end());


    double l = 0.0, r = 1e9, e = 1e-6, m1, m2;
    while (r - l > e) {
        m1 = l + ((r - l) / 3);
        m2 = r - ((r - l) / 3);
        if (calcMaxTime(data, m1) < calcMaxTime(data, m2)) {
            r = m2;
        } else {
            l = m1;
        }
    }

    cout << fixed << setprecision(9) << calcMaxTime(data, l);
}