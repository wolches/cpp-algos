#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int l = 1, r = n + 1, m;
    string res;
    while (l < r) {
        m = (l + r) / 2;
        cout << m << endl;
        cin >> res;
        if (res == "<") {
            r = m;
        } else {
            l = m + 1;
        }
    }
    cout << "! " << l - 1;
}

