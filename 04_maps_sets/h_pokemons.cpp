#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    unordered_set<int> pokemons;
    vector<int> data(n);
    for (int i = 0; i < n; ++i) {
        cin >> data[i];
        pokemons.insert(data[i]);
    }

    unordered_map<int, int> window;
    int l = 0, r = 0, min_distance = n;
    while (l < n && r < n) {
        if (window.size() == pokemons.size()) {
            int toReduce = window[data[l]];
            if (toReduce == 1) {
                window.erase(data[l]);
            } else {
                window[data[l]]--;
            }
            min_distance = min(min_distance, r - l);
            l++;
        } else {
            window[data[r++]]++;
        }
    }

    cout << min_distance;
}