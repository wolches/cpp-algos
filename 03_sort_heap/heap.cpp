#include <bits/stdc++.h>

using namespace std;

class Heap {
public:

    void add(int val) {
        if (values.size() == 0) {
            values.insert(values.begin(), 0);
        }
        values.push_back(val);
        sift_up(values.size() - 1);
    }

    int top() {
        return values[1];
    }

    void pop_top() {
        swap(values[1], values.back());
        values.pop_back();
        sift_down(1, values.size());
    }

private:

    vector<int> values;

    void sift_down(int i, int last) {
        while (true) {
            int max_son = -1;
            if (2 * i + 1 < last) {
                max_son = values[2 * i] > values[2 * i + 1] ? 2 * i : 2 * i + 1;
            } else if (2 * i < last) {
                max_son = 2 * i;
            }
            if (max_son == -1 || values[max_son] < values[i]) {
                break;
            }
            swap(values[max_son], values[i]);
            i = max_son;
        }
    }

    void sift_up(int i) {
        while (i > 1 && values[i] > values[i / 2]) {
            swap(values[i], values[i / 2]);
            i /= 2;
        }
    }
};