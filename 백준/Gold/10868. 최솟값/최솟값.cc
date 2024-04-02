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
vector<long> tree;

void maketree(int i) {
    while (i != 1) {
        if (tree[i / 2] > tree[i]) tree[i / 2] = tree[i];
        i--;
    }
}

long getmin(int s, int e) {
    long minres = LONG_MAX;

    while (s <= e) {
        if (s % 2 == 1) {
            minres = min(minres, tree[s]);
            s++;
        }
        if (e % 2 == 0) {
            minres = min(minres, tree[e]);
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

    cin >> N >> M;

    int treeheight = 0;
    int len = N;

    while (len != 0) {
        len /= 2;
        treeheight++;
    }
    int treesize = int(pow(2, treeheight + 1));
    int startindex = treesize / 2 - 1;

    tree.resize(treesize + 1);
    fill(tree.begin(), tree.end(), LONG_MAX);

    for (int i = startindex + 1; i <= startindex + N; i++) cin >> tree[i];
    maketree(treesize - 1);

    for (int i = 0; i < M; i++) {
        long s, e;
        cin >> s >> e;
        s += startindex;
        e += startindex;
        cout << getmin(s, e) << endl;
    }
    
    
}