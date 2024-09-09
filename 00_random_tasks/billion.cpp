//
// Created by anton on 05.09.2024.
//
#include <bits/stdc++.h>

using namespace std;

// O(MxN)
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int target = 100; // M

    vector<int> data;
    vector<int> result(target);

    int input;
    int i = 0;
    int maxRes;
    while (cin >> input) { // O(N)
        data.push_back(input);

        if (i < target) {
            result[i] = i++;
            continue;
        }

        maxRes = 0;
        for (int j = 0; j < target; ++j) { // O(M)
            if (data[result[j]] > data[result[maxRes]]) {
                maxRes = j;
            }
        }

        if (data[i] < data[result[maxRes]]) {
            result[maxRes] = i++;
        }
    }

    for (i = 0; i < target; ++i) {
        cout << result[i] << ' ';
    }
}