#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string t, p;
    getline(cin, t);
    getline(cin, p);

    vector<int> letters(t.size());
    for (int i = 0; i < t.size(); ++i) {
        cin >> letters[i];
    }

    int l = 0, r = letters.size() - 1, m, n, k;
    while (l < r) {
        m = l + ((r - l) / 2), n = 0, k = 0;
        string word = t;
        for (int i = 0; i < m; ++i) {
            word[letters[i] - 1] = '\0';
        }
        while (n < t.size() && k < p.size()) {
            if (p[k] == word[n]) {
                n++;
                k++;
            } else {
                n++;
            }
        }
        if (k < p.size()) {
            r = m;
        } else {
            l = m + 1;
        }
    }

    cout << (l > 0 ? l - 1 : l);
}