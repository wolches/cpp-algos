#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n;

    vector<pair<int, int>> data(n);
    for (int i = 0; i < n; ++i) {
        cin >> data[i].first;
        data[i].second = i;
    }

    std::sort(data.begin(), data.end());

    cin >> q;
    int l, r, x, found;

    for (int i = 0; i < q; ++i) {
        cin >> l >> r >> x;
        found = distance(data.begin(), lower_bound(data.begin(), data.end(), make_pair(x, l - 1)));
        bool condition = false;
        while (data[found].first == x && found < data.size()) {
            if (data[found].first == x && data[found].second >= l - 1 && data[found].second <= r - 1) {
                condition = true;
                break;
            }
            found++;
        }
        cout << (condition ? 1 : 0);
    }
}