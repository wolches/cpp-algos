#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    stack<char> data;
    string input;
    cin >> input;

    char c;
    char prevC;
    for (int i = 0; i < input.length(); i++) {
            c = input[i];
            //cout << c << " processing " << i << '\n';
            if (c == '(' || c == '[' || c == '{') {
                data.push(input[i]);
            } else {
                if (data.empty()) {
                    cout << "NO";
                    return 0;
                }
                prevC = data.top();
                data.pop();
                if (c == ')' && prevC != '(') {
                    cout << "NO";
                    return 0;
                } else if (c == ']' && prevC != '[') {
                    cout << "NO";
                    return 0;
                } else if (c == '}' && prevC != '{') {
                    cout << "NO";
                    return 0;
                } else {
                    continue;
                }
            }
    }

    if (data.empty()) {
        cout << "YES";
        return 0;
    } else {
        cout << "NO";
        return 0;
    }
}
