#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> first;
    vector<int> second;

    int x;
    for (int i = 0; i < n / 2; i++) {
        cin >> x;
        first.push_back(x);
    }
    for (int i = 0; i < n / 2; i++) {
        cin >> x;
        second.push_back(x);
    }

    int f;
    int s;
    int counter = 0;
    while (!(first.size() == 0) && !(second.size() == 0)) {
        if (counter == 200000) {
            cout << "draw ";
            return 0;
        }

        f = first[0];
        s = second[0];

        if (f == 0 && s == (n - 1)) {
            first.push_back(f);
            first.push_back(s);
            first.erase(first.begin());
            second.erase(second.begin());
        } else if (s == 0 && f == (n - 1)) {
            second.push_back(f);
            second.push_back(s);
            first.erase(first.begin());
            second.erase(second.begin());
        } else if (f > s) {
            first.push_back(f);
            first.push_back(s);
            first.erase(first.begin());
            second.erase(second.begin());
        } else if (s > f) {
            second.push_back(f);
            second.push_back(s);
            first.erase(first.begin());
            second.erase(second.begin());
        }
        counter++;
    }

    if (first.size() == 0) {
        cout << "second ";
        cout << counter;
    } else if (second.size() == 0) {
        cout << "first ";
        cout << counter;
    } else {
        cout << "draw ";
        cout << counter;
    }
}
