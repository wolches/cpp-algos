#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    unordered_map<string, int> repo;
    string name;
    int cmd, amount;

    while (n--) {
        cin >> cmd >> name;
        if (cmd == 1) {
            cin >> amount;
            repo[name] += amount;
        } else if (cmd == 2) {
            if (repo.count(name)) {
                cout << repo[name] << '\n';
            } else {
                cout << "ERROR" << '\n';
            }
        }
    }
}