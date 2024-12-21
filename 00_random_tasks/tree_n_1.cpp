#include <bits/stdc++.h>

using namespace std;

struct node {
    int prev;
    int zis;
    int left;
    int right;
};

vector<node> nodes(10000);
int last = 0;
char from; // 'l', 'r', 't'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    nodes[10] = {-1, 10, 5, 11};
    nodes[5] = {10, 5, 1, 6};
    nodes[1] = {5, 1, -1, -1};
    nodes[6] = {5, 6, 7, 8};
}