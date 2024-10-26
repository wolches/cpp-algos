#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    unordered_set<int> set;

    char cmd;
    int i;
    while (n--) {
        cin >> cmd >> i;
        switch (cmd) {
            case '+':
                set.insert(i);
                break;
            case '-':
                set.erase(i);
                break;
            case '?':
                cout << set.count(i) << '\n';
                break;
        }
    }
}