#include <bits/stdc++.h>
#define int64 long long

using namespace std;

const char min_char = 'A';
const int64 p = 31;
const int64 mod = 1'000'000'007;
vector<int64> pows;

int64 get_hash(const vector<int64>& subhash, int l, int r) {
    if (l == 0) {
        return subhash[r];
    }
    int64 ans = (subhash[r] - subhash[l - 1] * pows[r - l + 1]) % mod;
    return ans < 0 ? ans + mod : ans;
}

bool is_palyndrome(const vector<int64>& hf,
                             const vector<int64>& hr,
                             int center,
                             int size,
                             bool even) {
    int l, r;
    if (!even) {
        l = center - (size / 2);
        r = center + (size / 2);
        if (get_hash(hf, l, r) == get_hash(hr, l, r)) {
            return true;
        } else {
            return false;
        }
    } else {
        l = center - (size / 2) + 1;
        r = center + (size / 2);
        if (get_hash(hf, l, r) == get_hash(hr, l, r)) {
            return true;
        } else {
            return false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    cin >> str;
    vector<int64> hash_forward(str.size());
    vector<int64> hash_reversed(str.size());

    hash_forward[0] = str[0] - min_char + 1;
    for (int i = 1; i < str.size(); ++i) {
        hash_forward[i] = ((str[i - 1] * p) + (str[i] - 'A' + 1)) % mod;
    }
    hash_reversed[str.size() - 1] = str[str.size() - 1] - min_char + 1;
    for (int i = 2; i <= str.size(); ++i) {
        hash_reversed[str.size() - i] = ((str[str.size() - i + 1] * p) + (str[str.size() - i] - 'A' + 1)) % mod;
    }

    pows.push_back(1);
    for (int i = 1; i <= str.size(); ++i) {
        pows.push_back((pows[i - 1] * p) % mod);
    }

    int count = 0;
    for (int size = 1; size < str.size(); size++) {
        for (int i = 0 + size / 2; i < str.size() - size / 2; ++i) {
            if (is_palyndrome(hash_forward, hash_reversed, i, size, true)) {
                count++;
            }
            if (is_palyndrome(hash_forward, hash_reversed, i, size, false)) {
                count++;
            }
        }
    }

    cout << count;
}