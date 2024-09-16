#include <bits/stdc++.h>

using namespace std;

int count_ropes(vector<int> &ropes, int size);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> ropes(n);
    for (int i = 0; i < n; ++i) {
        cin >> ropes[i];
    }

    int l = 1, r = 1e9, m, c;
    while (l < r) {
        m = (l + r) / 2;
        c = count_ropes(ropes, m);
        if (c >= k) {
            l = m + 1;
        } else {
            r = m;
        }
    }

    cout << l - 1;
}

int count_ropes(vector<int> &ropes, int size) {
    int count = 0;
    for (const auto &item: ropes) {
        count += item / size;
    }
    return count;
}

