//
// Created by anton on 02.09.2024.
//
#include <bits/stdc++.h>

using namespace std;

int preSum(vector<int>& preSums, int l, int r) {
    return preSums[r] - (l == 0 ? 0 : preSums[l - 1]);
}

int calcDay(vector<int>& data, vector<int>& preSums, vector<int>& left, vector<int>& right, int i, int n) {
    int l = left[i] == -1 ? 0 : preSums[left[i]];
    int r = right[i] == n ? preSums[right[n - 1]] : preSums[right[i]];
    int sum = preSum(preSums, l, r);
    return sum * data[i];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> data(n);
    vector<int> preSums(n);
    vector<int> left(n);
    vector<int> right(n);

    for (int i = 0; i < n; ++i) {
        cin >> data[i];
        if (i == 0) {
            preSums[i] = data[i];
        } else {
            preSums[i] = data[i] + preSums[i - 1];
        }
    }

    stack<int> mins;
    for (int i = 0; i < n; ++i) {
        while (!mins.empty() && data[mins.top()] > data[i]) {
            mins.pop();
        }
        if (mins.empty()) {
            left[i] = -1;
            mins.push(i);
        } else {
            left[i] = mins.top();
            mins.push(i);
        }
    }

    while (!mins.empty()) {
        mins.pop();
    }

    for (int i = n - 1; i >= 0; --i) {
        while (!mins.empty() && data[mins.top()] > data[i]) {
            mins.pop();
        }
        if (mins.empty()) {
            right[i] = n;
            mins.push(i);
        } else {
            right[i] = mins.top();
            mins.push(i);
        }
    }

    int next, max, maxRes = -1;
    for (int i = 0; i < n; ++i) {
        next = calcDay(data, preSums, left, right, i, n);
        if (max == -1) {
            max = i;
            maxRes = next;
            continue;
        }
        if (next > maxRes) {
            max = i;
            maxRes = next;
        }
    }

    cout << maxRes << '\n';
    cout << left[max] << ' ' << right[max];
}

