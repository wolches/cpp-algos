#include <bits/stdc++.h>
#define uint unsigned int;

using namespace std;

const string insert = "Insert";
const string get_min = "GetMin";
const string get_max = "GetMax";

class Heap {
public:

    Heap(bool reversed) {
        this -> reversed = reversed;
    }

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

    size_t size() {
        return values.empty() ? 0 : values.size() - 1;
    }

private:

    bool reversed;
    vector<int> values;

    void sift_down(int i, int last) {
        while (true) {
            int max_son = -1;
            if ((2 * i + 1 < last) ^ reversed) {
                max_son = values[2 * i] > values[2 * i + 1] ? 2 * i : 2 * i + 1;
            } else if ((2 * i < last) ^ reversed) {
                max_son = 2 * i;
            }
            if (max_son == -1 || ((values[max_son] < values[i]) ^ reversed)) {
                break;
            }
            swap(values[max_son], values[i]);
            i = max_son;
        }
    }

    void sift_up(int i) {
        while (i > 1 && ((values[i] > values[i / 2]) ^ reversed)) {
            swap(values[i], values[i / 2]);
            i /= 2;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string input;
    cin >> n;
    getline(cin, input);

    int val;
    Heap max_heap(false);
    Heap max_deleted(false);
    Heap min_heap(true);
    Heap min_deleted(true);

    for (int i = 0; i < n; ++i) {
        getline(cin, input);
        if (input.find(insert) != std::string::npos) {
            input.replace(0, insert.size() + 1, ""); // Insert(
            input.replace(input.size() - 1, input.size(), ""); // )
            val = std::stoi(input);
            max_heap.add(val);
            min_heap.add(val);
        } else if (input.find(get_min) != std::string::npos) {
            while (min_deleted.size() > 0 && min_deleted.top() == min_heap.top()) {
                min_deleted.pop_top();
                min_heap.pop_top();
            }
            cout << min_heap.top() << '\n';
            max_deleted.add(min_heap.top());
            min_heap.pop_top();
        } else if (input.find(get_max) != std::string::npos) {
            while (max_deleted.size() > 0 && max_deleted.top() == max_heap.top()) {
                max_deleted.pop_top();
                max_heap.pop_top();
            }
            cout << max_heap.top() << '\n';
            min_deleted.add(max_heap.top());
            max_heap.pop_top();
        }
    }
}