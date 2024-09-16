#include <bits/stdc++.h>

using namespace std;

int find_first(const int val, const vector<int>& data) {
    int l = 0, r = data.size(), m;
    while (l < r) {
        m = (l + r) / 2;
        if (data[m] < val) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    return l;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }
    cin >> k;
    std::sort(numbers.begin(), numbers.end());
    int from, to, left, right;
    while (k--) {
        cin >> from >> to;
        left = find_first(from, numbers);
        right = find_first(to + 1, numbers);
        cout << right - left << ' ';
    }
}