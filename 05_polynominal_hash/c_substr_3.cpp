#include <bits/stdc++.h>
#define int64 long long

using namespace std;

const char min_char = 'A';
const int64 p = 31;
const int64 mod = 1'000'000'007;

int64 get_hash(const vector<int64>& subhash, const vector<int64>& pows, int l, int r) {
    if (l == 0) {
        return subhash[r];
    }
    int64 ans = (subhash[r] - subhash[l - 1] * pows[r - l + 1]) % mod;
    return ans < 0 ? ans + mod : ans;
}

pair<bool, string> has_substr_of_length(const vector<vector<int64>>& hashes,
                                        const vector<string>& strings,
                                        const vector<int64>& pows,
                                        const int len) {
    unordered_map<int64, pair<string, int>> res;
    for (int i = 0; i < strings.size(); i++) {
        unordered_map<int64, string> substrs;
        for (int l = 0; l <= strings[i].size() - len; l++) {
            int64 h = get_hash(hashes[i], pows, l, l + len - 1);
            substrs[h] = strings[i].substr(l, len);
        }
        for (const auto &item: substrs) {
            if (res.count(item.first)) {
                res[item.first].second++;
            } else {
                res[item.first] = {item.second, 1};
            }
        }
    }
    for (const auto& item : res) {
        if (item.second.second == strings.size()) {
            return {true, item.second.first};
        }
    }
    return {false, ""};
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
    vector<vector<int64>> h(n, vector<int64>());
    for (int i = 0; i < n; ++i) {
        h[i].push_back(strings[i][0] - min_char + 1);
        for (int j = 1; j < strings[i].size(); ++j) {
            h[i].push_back(((h[i][j - 1] * p) + (strings[i][j] - 'A' + 1)) % mod);
        }
    }
    vector<int64> pows(max_size + 1);
    pows[0] = 1;
    for (int i = 1; i <= max_size; ++i) {
        pows[i] = (pows[i - 1] * p) % mod;
    }

    int l = 0, r = min_size, m;
    pair<bool, string> res;
    while (l < r) {
        m = l + (r - l + 1) / 2;
        res = has_substr_of_length(h, strings, pows, m);
        if (res.first) {
            l = m;
        } else {
            r = m - 1;
        }
    }
    cout << res.second << '\n';
}
