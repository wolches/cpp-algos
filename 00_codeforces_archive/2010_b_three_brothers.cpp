#include <bits/stdc++.h>

using namespace std;

/**
 * https://codeforces.com/problemset/problem/2010/B
 */
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, c;
    cin >> a >> b;

    c = a == 1 ? (b == 2 ? 3 : 2) : (a == 2 ? (b == 1 ? 3 : 1) : (b == 1 ? 2 : 1));
    cout << c;
}