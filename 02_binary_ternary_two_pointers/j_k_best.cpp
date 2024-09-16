#include <bits/stdc++.h>

using namespace std;

double value(int v, int w) {
    return ((double) v) / w;
}

bool compare(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
    return value(a.first.first, a.first.second) < value(b.first.first, b.first.second);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<pair<pair<int, int>, int>> vwi(n);

    for (int i = 0; i < n; ++i) {
        cin >> vwi[i].first.first >> vwi[i].first.second;
        vwi[i].second = i;
    }

    std::sort(vwi.begin(), vwi.end(), compare);

    vector<int> ans;
    for (int i = n - k; i < n; ++i) {
        ans.push_back(vwi[i].second + 1);
    }
    std::sort(ans.begin(), ans.end());
    for (int i = 0; i < k; ++i) {
        cout << ans[i] << '\n';
    }
}