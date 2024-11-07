#include <bits/stdc++.h>
#define int64 long long

using namespace std;

const int64 p = 31;
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

    string input;
    cin >> input;

    int64 n = input.size();
    vector<int64> h(n);
    vector<int64> pows(n + 1);
    h[0] = input[0] - 'a' + 1;
    for (int i = 1; i < n; ++i) {
        h[i] = ((h[i - 1] * p) + (input[i] - 'a' + 1)) % mod;
    }
    pows[0] = 1;
    for (int i = 0; i < n; ++i) {
        pows[i + 1] = (pows[i] * p) % mod;
    }

    int queries;
    cin >> queries;
    int l1, l2, r1, r2;
    while (queries--) {
        cin >> l1 >> r1 >> l2 >> r2;
        l1--;
        l2--;
        r1--;
        r2--;
        int64 h1 = get_hash(h, pows, l1, r1);
        int64 h2 = get_hash(h, pows, l2, r2);
        bool cond = h1 == h2;
        cout << (cond ? "Yes\n" : "No\n");
    }
}