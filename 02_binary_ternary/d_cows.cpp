#include <bits/stdc++.h>

using namespace std;

bool checkCows(vector<int>& data, int targetDistance, int cows) {
    int lastCow = 0;
    cows--;
    for (int i = 1; i < data.size(); ++i) {
        if (data[i] - data[lastCow] >= targetDistance) {
            cows--;
            lastCow = i;
        }
    }
    return cows <= 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> data(n);

    for (int i = 0; i < n; ++i) {
        cin >> data[i];
    }

    int l = 0, r = data[n - 1], m;
    while (l < r) {
        m = (l + r) / 2;
        if (checkCows(data, m, k)) {
            l = m + 1;
        } else {
            r = m;
        }
    }

    cout << l - 1;
}

