#include <bits/stdc++.h>

using namespace std;

struct event {
    int coord, type, id;

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

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> intervals(n);
    vector<int> points(m);

    for (int i = 0; i < n; ++i) {
        cin >> intervals[i].first >> intervals[i].second;
        if (intervals[i].first > intervals[i].second) {
            swap(intervals[i].first, intervals[i].second);
        }
    }
    for (int i = 0; i < m; ++i) {
        cin >> points[i];
    }

    vector<event> events;
    for (const auto &item: intervals) {
        events.push_back({item.first, 0, -1});
        events.push_back({item.second, 2, -1});
    }
    for (int i = 0; i < m; ++i) {
        events.push_back({points[i], 1, i});
    }
    std::sort(events.begin(), events.end());

    int current = 0;
    vector<int> ans(m);
    for (const auto &item: events) {
        if (item.type == 0) {
            current++;
        } else if (item.type == 1) {
            ans[item.id] = current;
        } else {
            current--;
        }
    }
    for (int i = 0; i < m; ++i) {
        cout << ans[i] << ' ';
    }
}