#include <bits/stdc++.h>

using namespace std;

int calculate(const pair<int, int>& vw, int c) {
    return vw.first - (c * vw.second);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> vw(n);

    for (int i = 0; i < n; ++i) {
        cin >> vw[i].first >> vw[i].second;
    }

    int l = 0, r = 1e9, m, res;
    vector<pair<int, int>> values(n);
    while (l < r) {
        m = l + ((r - l) / 2);
        for (int i = 0; i < n; ++i) {
            values[i] = {calculate(vw[i], m), i};
        }
        std::sort(values.begin(), values.end());
        res = 0;
        for (int i = n - k; i < n; ++i) {
            res += values[i].first;
        }
        if (res < 0) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    if (res < 0) {
        m--;
        for (int i = 0; i < n; ++i) {
            values[i] = {calculate(vw[i], m), i};
        }
        std::sort(values.begin(), values.end());
    }

    vector<int> ans(k);
    for (int i = 0, j = n - k; i < k, j < n; ++i, ++j) {
        ans[i] = values[j].second;
    }
    std::sort(ans.begin(), ans.end());
    for (int i = 0; i < k; ++i) {
        cout << ans[i] << '\n';
    }
}