#include <bits/stdc++.h>

using namespace std;

int x0, x1, a, b, c;

uint32_t next() {
    uint32_t t = x0 * a + x1 * b + c;
    x0 = x1;
    x1 = t;
    return x0 >> 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q >> x0 >> x1 >> a >> b >> c;




    vector<int> nums(n);

}