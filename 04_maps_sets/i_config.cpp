#include <bits/stdc++.h>

using namespace std;

void readLine(unordered_map<string, int>& vars, string input);
void readBlock(unordered_map<string, int> vars);

void readLine(unordered_map<string, int>& vars, string input) {
    if (input == "{") {
        readBlock(vars);
    } else if (/* var = x */) {

    } else if (/* var1 = var2 */) {

    }
}

void readBlock(unordered_map<string, int> vars) {
    string input;
    while (cin >> input) {
        if (input == "}") {
            return;
        }
        readLine(vars, input);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_map<string, int> vars;

    string input;
    while (cin >> input) {
        readLine(vars, input);
    }
}