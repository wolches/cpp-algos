#include <bits/stdc++.h>
#define int64 long long

using namespace std;

const char min_char = 'a';
const int64 p = 31;
const int64 mod = 1'000'000'007;

int64 get_hash(const vector<int64>& subhash, const vector<int64>& pows, int l, int r) {
    if (l == 0) {
        return subhash[r];
    }
    int64 ans = (subhash[r] - subhash[l - 1] * pows[r - l + 1]) % mod;
    return ans < 0 ? ans + mod : ans;
}

int64 fillSubs(unordered_map<int64, string>& substrings_by_hash,
              const vector<string>& strings,
              const vector<vector<int64>>& h,
              const vector<int64>& pows,
              int minIdx) {
    int length = 1;

    //vector<int64>

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, min_str_index;
    size_t max_size = 0, min_size = 1e9;
    cin >> n;

    vector<string> strings(n);
    for (int i = 0; i < n; ++i) {
        cin >> strings[i];
        max_size = std::max(strings[i].size(), max_size);
        if (strings[i].size() < min_size) {
            min_str_index = i;
        }
        min_size = std::min(strings[i].size(), min_size);
    }
    vector<vector<int64>> h(n);
    for (int i = 0; i < n; ++i) {
        h[i].push_back(strings[i][0] - min_char + 1);
        for (int j = 1; j < strings[i].size(); ++j) {
            h[i].push_back(((h[i][j - 1] * p) + (strings[i][i] - 'a' + 1)) % mod);
        }
    }
    vector<int64> pows(max_size);
    pows[0] = 1;
    for (int i = 0; i < pows.size(); ++i) {
        pows[i + 1] = (pows[i] * p) % mod;
    }

    unordered_map<int64, string> substrings_by_hash;
    int64 res = fillSubs(substrings_by_hash, strings, h, pows, min_str_index);
    cout << substrings_by_hash[res];
}