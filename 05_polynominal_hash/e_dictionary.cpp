#include <bits/stdc++.h>
#define int64 long long

using namespace std;

const char min_char = 'a';
const int64 p = 29;
const int64 mod = 1'000'000'007;
vector<int64> pows(32);

int64 get_hash(const vector<int64>& subhash, int l, int r) {
    if (l == 0) {
        return subhash[r];
    }
    int64 ans = (subhash[r] - subhash[l - 1] * pows[r - l + 1]) % mod;
    return ans < 0 ? ans + mod : ans;
}

vector<int64> hash_window(string s, int window_size) {
    vector<int64> h(s.size());
    h[0] = s[0] - min_char + 1;
    for (int i = 1; i < s.size(); ++i) {
        if (i <= window_size) {
            h[i] = ((h[i - 1] * p) + (h[i] - min_char + 1)) % mod;
        } else {
            h[i] = ((h[i - 1] * p) + (h[i] - min_char + 1) - (h[i - window_size] * pows[window_size])) % mod;
        }
    }
    return h;
}

int64 hash_word(string s) {
    vector<int64> h(s.size());
    h[0] = s[0] - min_char + 1;
    for (int i = 1; i < s.size(); ++i) {
        h[i] = ((h[i - 1] * p) + (h[i] - min_char + 1)) % mod;
    }
    return h[s.size() - 1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int window = 31;
    pows[0] = 1;
    for (int i = 0; i < window; ++i) {
        pows[i + 1] = (pows[i] * p) % mod;
    }

    string text;
    int n;
    cin >> text;
    vector<int64> ht = hash_window(text, window);

    cin >> n;
    string word;
    while (n--) {
        cin >> word;
        if (word.size() > text.size()) {
            cout << "No" << '\n';
        } else {
            int64 hw = hash_word(word);
            bool found = false;
            for (int i = 0; i <= text.size() - word.size(); ++i) {
                int64 test_hash = get_hash(ht, i, i + word.size() - 1);
                if (test_hash == hw) {
                    found = true;
                    break;
                }
            }
            cout << (found ? "Yes" : "No") << '\n';
        }
    }
}