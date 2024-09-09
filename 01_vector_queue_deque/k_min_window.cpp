#include <bits/stdc++.h>
#include <vector>

using namespace std;

class MinQueue {
private:
    stack<pair<int, int>> st1;
    stack<pair<int, int>> st2;

public:
    void push(int x) {
        st1.push({x, st1.empty() ? x : std::min(x, st1.top().second)});
    }

    void pop() {
        if (st2.empty()) {
            while (!st1.empty()) {
                st2.push({
                                 st1.top().first,
                                 st2.empty() ? st1.top().first : std::min(st1.top().first, st2.top().second)
                         });
                st1.pop();
            }
        }
        st2.pop();
    }

    int min() {
        if (st2.empty()) {
            while(!st1.empty()) {
                st2.push({
                    st1.top().first,
                    st2.empty() ? st1.top().first : std::min(st1.top().first, st2.top().second)
                });
                st1.pop();
            }
        }
        return std::min(st2.top().second, st1.empty() ? 32768 : st1.top().second);
    }

    int size() {
        return st1.size() + st2.size();
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> data(n);
    MinQueue q;

    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }
    for (int i = 0; i < n; i++) {
        q.push(data[i]);
        if (q.size() == k) {
            cout << q.min() << '\n';
            q.pop();
        }
    }
}

