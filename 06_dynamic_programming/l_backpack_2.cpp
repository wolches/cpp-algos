#include <bits/stdc++.h>

using namespace std;

struct itm {
    int m, c;
};

struct dp {
    vector<bool> i;
    int m, c;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<itm> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].m;
    }
    for (int i = 0; i < n; ++i) {
        cin >> a[i].c;
    }


}