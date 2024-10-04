#include <bits/stdc++.h>

using namespace std;

struct event {
    int id, a, type;

    bool operator<(const event& arg) const {
        if (id != arg.id) {
            return id < arg.id;
        }
        return type < arg.type;
    }
};

struct train_stop {

};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int k;
    cin >> k;

    vector<event> ev;
    char action;
    int i, j = 0, m = 0;
    while (true) {
        cin >> action;
        cin >> i;
        if (action == '+') {
            ev.push_back({j++, i, 0});
            ++m;
        } else {
            ev.push_back({j++, i, 1});
            --m;
        }
        if (m == 0) {
            break;
        }
    }

    vector<pair<int, int>> ans(j / 2);

    for (const auto &item: ev) {
        if (item.type == 0) {
            if (m < k) {
                ans.push_back({item.a, m++});
            } else {
                cout << 0 << ' ' << item.a;
                return 0;
            }
        } else {

        }
    }


}