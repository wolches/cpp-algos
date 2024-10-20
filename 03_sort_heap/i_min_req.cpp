#include <bits/stdc++.h>
#define uint uint32_t

using namespace std;

const uint m232 = 0xffffffff;
int x0, x1, a, b, c;

uint next() {
    uint t = x0 * a + x1 * b + c;
    x0 = x1;
    x1 = t;
    return x0 >> 2;
}

size_t findMin(vector<uint>& array) {
    size_t min = 0;
    for (size_t i = 0; i < array.size(); ++i) {
        if (array[i] < array[min]) {
            min = i;
        }
    }
    return min;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    uint n, q;
    cin >> n >> q >> x0 >> x1 >> a >> b >> c;

    vector<uint> array(n);
    size_t min_id = 0;
    for (int i = 0; i < n; ++i) {
        array[i] = m232;
    }

    uint res, sum = 0, multiply = 10099;
    size_t next_id;

    while (q--) {
        uint i = next();
        uint x = next();
        next_id = i % n;
        array[next_id] = x;
        //cout << "a[" << i % n << "] = " << x << '\n';
        if (next_id == min_id) {
            min_id = findMin(array);
        } else {
            if (array[next_id] < array[min_id]) {
                min_id = next_id;
            }
        }

        //cout << "min = " << array[1] << '\n';

        res = array[min_id] * multiply;

        sum += res;
        multiply *= 10099;
    }

    cout << sum;
}