#include <bits/stdc++.h>

using namespace std;

void mergeSort(vector<int>& a, int l, int r) {
    if (l + 1 >= r) {
        return;
    }
    int m = l + (r - l) / 2;
    mergeSort(a, l, m);
    mergeSort(a, m, r);
    int i = l, j = m, k = 0;
    vector<int> b(r - l);

    while (i < m || j < r) {
        if (i == m) {
            b[k++] = a[j++];
        } else if (j == r) {
            b[k++] = a[i++];
        } else if (a[i] < a[j]) {
            b[k++] = a[i++];
        } else {
            b[k++] = a[j++];
        }
    }
    k = 0;
    for (int i = l; i < r; ++i) {
        a[i] = b[k++];
    }
}