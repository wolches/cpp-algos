//
// Created by anton on 02.09.2024.
//
#include <bits/stdc++.h>

using namespace std;

int preSum(vector<int>& preSums, int l, int r) {
    return preSums[r] - (l == 0 ? 0 : preSums[l - 1]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> data(n);
    vector<int> preSums(n);
    vector<int> prev(n);
    vector<int> next(n);
    vector<int> periods(n);

    for (int i = 0; i < n; ++i) {
        cin >> data[i];
        if (i == 0) {
            preSums[i] = data[i];
        } else {
            preSums[i] = data[i] + preSums[i - 1];
        }
    }

    int j;
    for (int i = 0; i < n; ++i) {
        j = i;
        if (i != 0 && data[i - 1] >= data[i]) {
            j = prev[i - 1];
        }
        while ((j > -1) && (data[j] >= data[i])) {
            j--;
        }
        prev[i] = j;
    }

    for(int i = n - 1; i >= 0; --i) {
        j = i;
        if (i != n - 1 && data[i + 1] >= data[i]) {
            j = next[i + 1];
        }
        while ((j < n) && (data[j] >= data[i])) {
            j++;
        }
        next[i] = j;
    }

    int idx = 0;
    for (int i = 1; i < n; ++i) {
        periods[i] = preSum(preSums, prev[i] + 1, next[i] - 1) * data[i];
        if (periods[i] > periods[idx]) {
            idx = i;
        }
    }

    cout << periods[idx] << '\n'
         << prev[idx] + 2 << ' ' << next[idx];
}

