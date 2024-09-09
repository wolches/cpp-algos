#include <bits/stdc++.h>

using namespace std;

/**
 * https://codeforces.com/problemset/problem/4/A
 */
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int w;
    cin >> w;

    int maxP = w - 2;
    cout << ((maxP > 0 && (maxP % 2) == 0) ? "YES" : "NO");
}