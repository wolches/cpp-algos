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

    double l, r, m, ans;
    for (int i = 0; i < n - 1; ++i) {
        l = data[i].first;
        r = data[i + 1].first;
        while (r - l > 1e-9) {
            m = l + ((r - l) / 2);
            if (calcMaxTime(data, l) > calcMaxTime(data, m)) {
                l = m;
            } else {
                r = m;
            }
        }
        if (i == 0) {
            ans = calcMaxTime(data, l);
        } else {
            ans = min(calcMaxTime(data, l), ans);
        }
    }

    cout << fixed << setprecision(9) << ans;
}