#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<long long>> dp(n + 1, vector<long long>(10));

    for (int i = 1; i < 10; ++i) {
        dp[1][i] = 1;
    }

    for (int i = 2; i <= n; ++i) { // Длина числа
        for (int j = 0; j < 10; ++j) { // Последняя цифра
            dp[i][j] = dp[i - 1][j]; // Может заканчиваться на ту же цифру что и предпоследняя
            if (j != 9) { // Может быть больше предпоследней
                dp[i][j] += dp[i - 1][j + 1];
            }
            if (j != 0) { // Может быть меньше предпоследней
                dp[i][j] += dp[i - 1][j - 1];
            }
        }
    }
    // Таблица для дебага
    /*cout << "  | ";
    for (int j = 0; j < 10; ++j) {
        cout << j << ' ';
    }
    cout << "\n------------------------\n";
    for (int i = 0; i <= n; ++i) {
        cout << i << " | ";
        for (int j = 0; j < 10; ++j) {
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }*/

    long long ans = 0;
    for (int j = 0; j < 10; ++j) {
        ans += dp[n][j];
    }
    cout << ans;
}