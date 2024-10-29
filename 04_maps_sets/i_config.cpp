#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_map<string, stack<int>> vars;
    stack<unordered_map<string, int>> changes;

    unordered_map<string, int> bottom;
    changes.push(bottom);
    string input;
    while (cin >> input) {
        if (input == "{") {
            unordered_map<string, int> nextFrame;
            changes.push(nextFrame);
        } else if (input == "}") {
            unordered_map<string, int> lastFrame = changes.top();
            changes.pop();
            for (const auto &item: lastFrame) {
                for (int i = 0; i < item.second; ++i) {
                    vars[item.first].pop();
                }
            }
        } else {
            string var = input.substr(0, input.find('='));
            string val = input.substr(input.find('=') + 1, input.size());
            if ((val[0] >= '0' && val[0] <= '9') || val[0] == '-') {
                if (vars.count(var) == 0) {
                    stack<int> newStack;
                    vars.insert({var, newStack});
                }
                vars[var].push(stoi(val));
                changes.top()[var]++;
            } else {
                if (vars.count(var) == 0) {
                    stack<int> newStack;
                    vars.insert({var, newStack});
                    vars[var].push(0);
                }
                if (vars.count(val) == 0) {
                    stack<int> newStack;
                    vars.insert({val, newStack});
                    vars[val].push(0);
                }
                vars[var].push(vars[val].top());
                changes.top()[var]++;
                cout << vars[var].top() << '\n';
            }
        }
    }
}