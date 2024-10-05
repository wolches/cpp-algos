#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long k;
    cin >> n >> k;

    vector<pair<int, int>> birds(n);

    for (int i = 0; i < n; ++i) {
        cin >> birds[i].first >> birds[i].second;
    }

    std::sort(birds.begin(), birds.end());

    long long cur = 0;
    for (const auto &item: birds) {
        cur += item.second;
        if (cur >= k) {
            cout << item.first;
            return 0;
        }
    }
}