#include <bits/stdc++.h>

using namespace std;

/**
 * https://codeforces.com/problemset/problem/231/A
 */
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int a, b, c, count = 0;
    while (n--) {
        cin >> a >> b >> c;
        if (a + b + c >= 2) {
            count++;
        }
    }

    cout << count;
}