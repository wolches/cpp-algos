#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    stack<int> values;
    string input;

    getline(cin, input);

    int a;
    int b;
    int prevSeparator = -1;
    for (int i = 0; i < input.size(); i++) {
        if (input[i] == '+') {
            a = values.top();
            values.pop();
            b = values.top();
            values.pop();

            values.push(a + b);
        } else if (input[i] == '-') {
            a = values.top();
            values.pop();
            b = values.top();
            values.pop();

            values.push(b - a);
        } else if (input[i] == '*') {
            a = values.top();
            values.pop();
            b = values.top();
            values.pop();

            values.push(a * b);
        } else if (input[i] == ' ') {
            if (
                input[i - 1] != '+'
                && input[i - 1] != '-'
                && input[i - 1] != '*'
            ) {
                b = stoi(input.substr(prevSeparator + 1, i));
                values.push(b);
            }
            prevSeparator = i;
        }
    }

    cout << values.top();
}
