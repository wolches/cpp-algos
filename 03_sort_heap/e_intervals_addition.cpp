#include <bits/stdc++.h>

using namespace std;

struct event {
    int coord, type;

    bool operator<(const event& arg) const {
        if (coord != arg.coord) {
            return coord < arg.coord;
        }
        return type < arg.type;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int, int>> intervals(n);

    for (int i = 0; i < n; ++i) {
        cin >> intervals[i].first >> intervals[i].second;
        if (intervals[i].first > intervals[i].second) {
            swap(intervals[i].first, intervals[i].second);
        }
    }

    vector<event> events;
    for (const auto &item: intervals) {
        events.push_back({item.first, 0});
        events.push_back({item.second, 1});
    }

    std::sort(events.begin(), events.end());
    int cur = 0, l;
    vector<pair<int, int>> ans;

    for (const auto &item: events) {
        if (item.type == 0) {
            if (cur++ == 0) {
                l = item.coord;
            }
        } else {
            if (--cur == 0) {
                ans.push_back({l, item.coord});
            }
        }
    }

    cout << ans.size() << '\n';
    for (const auto &item: ans) {
        cout << item.first << ' ' << item.second << '\n';
    }
}