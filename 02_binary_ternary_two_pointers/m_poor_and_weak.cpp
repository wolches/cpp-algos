#include <bits/stdc++.h>

using namespace std;

pair<int, int> find_max(vector<int> a) {
    int ans = a[0];
    int ans_l = 0;
    int ans_r = 0;
    int sum = 0;
    int min_sum = 0;
    int min_pos = -1;
    for (int r = 0; r < a.size(); ++r) {
        sum += a[r];

        int cur = sum - min_sum;
        if (cur > ans) {
            ans = cur;
            ans_l = min_pos + 1;
            ans_r = r;
        }

        if (sum < min_sum) {
            min_sum = sum;
            min_pos = r;
        }
    }

    return {ans_l, ans_r};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> sum_a(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (i != 0) {
            sum_a[i] = sum_a[i - 1] + a[i];
        } else {
            sum_a[i] = a[i];
        }
    }

    double l = -1e4, r = 1e4, m1, m2, e = 1e-9;
    while (r - l > e) {
        // TODO
    }
}