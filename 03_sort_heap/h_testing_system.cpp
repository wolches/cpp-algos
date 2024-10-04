#include <bits/stdc++.h>

using namespace std;

struct record {
    int id, s, t;

    bool operator<(const record& arg) const {
        if (s != arg.s) {
            return s < arg.s;
        } else if (t != arg.t) {
            return t > arg.t;
        } else {
            return id > arg.id;
        }
    }
};



void merge_sort(vector<record>& array, int l, int r) {
    if (l + 1 >= r) {
        return;
    }
    int n = r - l;
    int m = l + n / 2;
    merge_sort(array, l, m);
    merge_sort(array, m, r);

    vector<record> new_array(n);
    int i = l, j = m, k = 0;
    while (i < m || j < r) {
        if (i == m) {
            new_array[k++] = array[j++];
        } else if (j == r) {
            new_array[k++] = array[i++];
        } else if (array[i] < array[j]) {
            new_array[k++] = array[j++];
        } else {
            new_array[k++] = array[i++];
        }
    }
    for (i = 0; i < n; ++i) {
        array[l + i] = new_array[i];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<record> records(n);

    int s, t;
    for (int i = 0; i < n; ++i) {
        cin >> s >> t;
        records[i] = {i, s, t};
    }

    merge_sort(records, 0, n);

    for (int i = 0; i < n; ++i) {
        cout << records[i].id + 1 << ' ';
    }
}