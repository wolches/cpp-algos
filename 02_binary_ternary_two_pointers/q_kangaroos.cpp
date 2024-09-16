#include <bits/stdc++.h>

using namespace std;

int count_ropes(vector<int> &ropes, int size);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> kangaroos(n);
    for (int i = 0; i < n; ++i) {
        cin >> kangaroos[i];
    }

    if (n == 0 || n == 1) {
        cout << n;
        return 0;
    }

    std::sort(kangaroos.begin(), kangaroos.end());

    int first = 0;
    int second = n / 2 + (n % 2 == 0 ? 0 : 1);
    int first_end = second;
    int removed = 0;
    while(first < first_end && second < n) {
        if (kangaroos[first] * 2 <= kangaroos[second]) {
            removed++;
            first++;
            second++;
        } else {
            second++;
        }
    }

    cout << n - removed;
}

