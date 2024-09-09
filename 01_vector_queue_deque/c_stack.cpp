#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    stack<pair<int, int>> data;
    int x;
    int t;

    while (n--) {
        cin >> t;
        if (t == 1) {
            cin >> x;
            if (data.size() == 0) {
                data.push({x, x});
            } else {
                data.push({x, min(x, data.top().second)});
            }
        } else if (t == 2) {
            data.pop();
        } else {
            cout << data.top().second << '\n';
        }
    }
}
