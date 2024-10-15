#include <bits/stdc++.h>

using namespace std;

struct event {
    int t, type, id;

    bool operator<(const event& arg) const {
        if (t != arg.t) {
            return t < arg.t;
        }
        return type < arg.type;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, h, m, s1, s2;
    cin >> n;

    vector<event> ev;
    for (int i = 0; i < n; ++i) {
        cin >> h >> m >> s1;
        m += h * 60;
        s1 += m * 60;
        cin >> h >> m >> s2;
        m += h * 60;
        s2 += m * 60;

        if (s1 == s2) {
            s1 = 0;
            s2 = 86400;
            ev.push_back({s1, 1, i});
            ev.push_back({s2, 0, i});
        } else if (s1 < s2) {
            ev.push_back({s1, 1, i});
            ev.push_back({s2, 0, i});
        } else {
            ev.push_back({s1 - 86400, 1, i});
            ev.push_back({s2, 0, i});
            ev.push_back({s1, 1, i});
        }

    }

    std::sort(ev.begin(), ev.end());

    int curr = 0, total = 0;
    int t1;

    for (const auto &item: ev) {
        if (item.type == 1) {
            curr++;
            if (curr == n) {
                t1 = item.t;
            }
        } else {
            if (curr == n) {
                total += item.t - t1;
            }
            curr--;
        }
    }

    cout << total;
}