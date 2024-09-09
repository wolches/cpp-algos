#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> data(2 * n);
    vector<int> pos(1e5);

    int l = n / 2, r = n / 2;
    int x, y;
    while(n--) {
        cin >> x;
        if (x == 1) {
            cin >> y;
            data[r] = y;
            pos[y] = r;
            r++;
        } else if (x == 2) {
            l++;
        } else if (x == 3) {
            r--;
        } else if (x == 4) {
            cin >> y;
            cout << (pos[y] - l) << '\n';
        } else if (x == 5) {
            cout << data[l] << '\n';
        }
    }
}
