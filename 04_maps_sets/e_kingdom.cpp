#include <bits/stdc++.h>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int, int>> castles;
    set<pair<char, int>> lines;

    int x, y;
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        castles.push_back({x, y});
    }
    std::sort(castles.begin(), castles.end());

    pair<int, int> cur, prev;
    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            continue;
        }
        cur = castles[i];
        prev = castles[i - 1];
        if (cur.first != prev.first) {
            lines.insert({'x', cur.first});
        } else {
            lines.insert({'y', cur.second});
        }
    }

    for (const auto &item: lines) {
        cout << item.first << ' ' << item.second << '\n';
    }
}