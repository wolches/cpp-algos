#include <bits/stdc++.h>

using namespace std;

struct mountain {
    int l, x, r, y, id;

    bool operator<(const mountain& arg) const {
        if (l != arg.l) {
            return l < arg.l;
        }
        return y > arg.y;
    }

    bool operator>(const mountain& arg) const {
        if (l != arg.l) {
            return l > arg.l;
        }
        return y < arg.y;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x, y;
    cin >> n;
    vector<mountain> m(n);

    for (int i = 0; i < n; ++i) {
        cin >> x;
        cin >> y;
        m[i] = {x - y, x, x + y, y, i};
    }

}