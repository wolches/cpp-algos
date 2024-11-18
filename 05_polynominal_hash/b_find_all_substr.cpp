#include <bits/stdc++.h>
#define int64 size_t

using namespace std;

const char min_char = 'A';
const int64 pp = 59;
const int64 mod = 1'000'000'007;

int64 get_hash(const vector<int64>& subhash, const vector<int64>& pows, int l, int r) {
    if (l == 0) {
        return subhash[r];
    }
    int64 ans = (subhash[r] - subhash[l - 1] * pows[r - l + 1]) % mod;
    return ans < 0 ? ans + mod : ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string p, t;
    cin >> p >> t;

    int64 n = t.size(), k = p.size();
    vector<int64> ht(n);
    vector<int64> hp(k);
    vector<int64> pows(n + 1);
    // Hash t
    ht[0] = t[0] - min_char + 1;
    for (int i = 1; i < n; ++i) {
        ht[i] = ((ht[i - 1] * pp) + (t[i] - min_char + 1)) % mod;
    }
    // Hash p
    hp[0] = p[0] - min_char + 1;
    for (int i = 1; i < k; ++i) {
        hp[i] = ((hp[i - 1] * pp) + (p[i] - min_char + 1)) % mod;
    }
    // Pows
    pows[0] = 1;
    for (int i = 0; i < n; ++i) {
        pows[i + 1] = (pows[i] * pp) % mod;
    }

    vector<int> iis;
    for(int i = 0; i <= n - k; i++) {
        int64 window_hash = get_hash(ht, pows, i, i + k - 1);
        if (window_hash == hp[k - 1]) {
            iis.push_back(i);
        }
    }

    cout << iis.size() << '\n';
    for (const auto &item: iis) {
        cout << item + 1 << ' ';
    }
}