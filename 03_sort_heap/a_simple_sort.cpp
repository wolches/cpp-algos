#include <bits/stdc++.h>

using namespace std;

pair<int, int> partition(vector<int>& a, int l, int r, int pivot) {
    pair<int, int> ans;
    int last = l;
    for (int i = l; i < r; ++i) {
        if (a[i] < pivot) {
            swap(a[i], a[last]);
            ++last;
        }
    }
    ans.first = last;
    for (int i = last; i < r; ++i) {
        if (a[i] == pivot) {
            swap(a[i], a[last]);
            ++last;
        }
    }
    ans.second = last;
    return ans;
}

void quickSort(vector<int>& a, int l, int r) {
    if (l + 1 >= r) {
        return;
    }
    int pivot = a[l + rand() % (r - l)];
    auto m = partition(a, l, r, pivot);
    quickSort(a, l, m.first);
    quickSort(a, m.second, r);
}

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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> data(n);
    for (int i = 0; i < n; ++i) {
        cin >> data[i];
    }

    mergeSort(data, 0, n);

    for (int i = 0; i < n; ++i) {
        cout << data[i] << ' ';
    }
}