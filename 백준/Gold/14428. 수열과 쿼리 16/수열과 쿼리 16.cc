#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <limits.h>
#define endl '\n'
#define pll pair<long, long>
using ll = long long;
using namespace std;

int N, M;
vector<pll> tree;
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

pll getmin(int s, int e) {
    pll minres = {LONG_MAX, 0};

    while (s <= e) {
        if (s % 2 == 1) {
            if (minres.first > tree[s].first) minres = tree[s];
            else if (minres.first == tree[s].first) {
                if (minres.second > tree[s].second) minres = tree[s];
            }
            s++;
        }
        if (e % 2 == 0) {
            if (minres.first > tree[e].first) minres = tree[e];
            else if (minres.first == tree[e].first) {
                if (minres.second > tree[e].second) minres = tree[e];
            }
            e--;
        }

        s /= 2;
        e /= 2;
    }

    return minres;
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
    tree.resize(treesize + 1, {LONG_MAX, 0});

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        tree[i + startindex] = {arr[i], i};
    }
    maketree(treesize - 1);

    cin >> M;

    for (int i = 0; i < M; i++) {
        long a, b, c;
        cin >> a >> b >> c;

        if (a == 1) {
            b += startindex;
            change(b, c);
        }
        else if (a == 2) {
            b += startindex;
            c += startindex;
            cout << getmin(b, c).second << endl;
        }
    }
    
    
}