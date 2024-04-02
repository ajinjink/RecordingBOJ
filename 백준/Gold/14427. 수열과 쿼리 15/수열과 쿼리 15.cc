#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <limits.h>
#define endl '\n'
#define pii pair<int, int>
using ll = long long;
using namespace std;

int N, M;
vector<pii> tree;
vector<int> arr;

void maketree(int i) {
    while (i != 1) {
        if (tree[i / 2].first >= tree[i].first) tree[i / 2] = tree[i];
        i--;
    }
}

void change(long index, long val) {
    tree[index].first = val;

    while (index > 1) {
        index = index / 2;
        if (tree[index * 2] <= tree[index * 2 + 1]) tree[index] = tree[index * 2];
        else tree[index] = tree[index * 2 + 1];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    int treeheight = 0;
    int len = N;
    while (len != 0) {
        len /= 2;
        treeheight++;
    }
    int treesize = int(pow(2, treeheight + 1));
    int startindex = treesize / 2 - 1;

    arr.resize(N + 1);
    tree.resize(treesize + 1, {INT_MAX, 0});

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        tree[i + startindex] = {arr[i], i};
    }
    maketree(treesize - 1);

    cin >> M;

    for (int i = 0; i < M; i++) {
        long a, b, c;
        cin >> a;

        if (a == 1) {
            cin >> b >> c; // index, new value
            b += startindex;
            change(b, c);
        }
        else if (a == 2) {
            cout << tree[1].second << endl;
        }
    }
    
    
}