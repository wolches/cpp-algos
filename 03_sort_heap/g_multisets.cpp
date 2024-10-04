#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> nums(n);

    int sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
        sum += nums[i];
    }

    if (sum % 5 != 0) {
        cout << "No";
        return 0;
    }

    std::sort(nums.begin(), nums.end());
    sum = sum / 5;
    int i = 0, counter = 0, cur = 0;
    for (;i < n && counter < 5; i++) {
        cur += nums[i];
        if (cur == sum) {
            counter++;
            cur = 0;
        } else if (cur > sum) {
            cout << "No";
            return 0;
        }
    }

    cout << (counter == 5 && cur == 0 ? "Yes" : "No");
}