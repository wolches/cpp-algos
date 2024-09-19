#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> drills(n), dowels(m);

    for (int i = 0; i < n; ++i) {
        cin >> drills[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> dowels[i];
    }

    int i = 0, j = 0, min = 5e6;
    while (i < n && j < m) {
        min = std::min(min, abs(drills[i] - dowels[j]));
        if (drills[i] > dowels[j]) {
            j++;
        } else {
            i++;
        }
    }

    cout << min;
}

