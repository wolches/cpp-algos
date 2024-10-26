#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    set<int> set;
    string cmd;
    int i;
    while (cin >> cmd >> i) {
        if (cmd == "insert") {
            set.insert(i);
        } else if (cmd == "delete") {
            set.erase(i);
        } else if (cmd == "exists") {
            cout << (set.count(i) > 0 ? "true" : "false") << '\n';
        } else if (cmd == "next") {
            auto lb = set.upper_bound(i);
            if (lb == set.end()) {
                cout << "none" << '\n';
            } else {
                cout << *lb << '\n';
            }
        } else if (cmd == "prev") {
            auto lb = set.lower_bound(i);
            if (lb == set.begin()) {
                cout << "none" << '\n';
            } else {
                cout << *(--lb) << '\n';
            }
        }
    }
}