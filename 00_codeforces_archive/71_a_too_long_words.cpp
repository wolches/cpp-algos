#include <bits/stdc++.h>

using namespace std;

/**
 * https://codeforces.com/problemset/problem/71/A
 */
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    string word;
    while (n--) {
        cin >> word;
        if (word.length() > 10) {
            cout << word[0] << word.length() - 2 << word[word.length() - 1] << '\n';
        } else {
            cout << word << '\n';
        }
    }
}