#include <bits/stdc++.h>
#define uint uint32_t

using namespace std;

const uint m232 = 0xffffffff;
int x0, x1, a, b, c;

uint next() {
    uint32_t t = x0 * a + x1 * b + c;
    x0 = x1;
    x1 = t;
    return x0 >> 2;
}

void sift_up(vector<uint>& array, uint i) {
    while (i > 1 && array[i] < array[i / 2]) {
        swap(array[i], array[i / 2]);
        i /= 2;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    uint n, q;
    cin >> n >> q >> x0 >> x1 >> a >> b >> c;

    vector<uint> array(n + 1);
    for (int i = 0; i < n + 1; ++i) {
        array[i] = m232;
    }

    uint res, sum = 0, multiply = 10099;

    while (q--) {
        uint i = next();
        uint x = next();
        array[i % n + 1] = x;
        //cout << "a[" << i % n << "] = " << x << '\n';
        sift_up(array, i % n + 1);
        //cout << "min = " << array[1] << '\n';

        res = array[1] * multiply;

        sum += res;
        multiply *= 10099;
    }

    cout << sum;
}