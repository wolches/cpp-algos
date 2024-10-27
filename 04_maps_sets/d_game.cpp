#include <bits/stdc++.h>
#define uint uint64_t

using namespace std;

void add(set<uint>& values, uint next) {
    if (values.count(next)) {
        values.erase(next);
        next = next * 2;
        add(values, next);
    } else {
        values.insert(next);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    set<uint> values;
    uint next;
    while (n--) {
        cin >> next;
        add(values, next);
    }

    auto max = std::max_element(values.begin(), values.end());
    cout << (max.operator*());
}