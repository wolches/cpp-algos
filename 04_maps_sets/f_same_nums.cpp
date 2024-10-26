#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    unordered_map<int, int> last;
    vector<int> ans(n);
    int next;
    for (int i = 0; i < n; ++i) {
        cin >> next;
        cout << ((last.count(next)) ? i - last[next] : i) << ' ';
        last[next] = i;
    }
}