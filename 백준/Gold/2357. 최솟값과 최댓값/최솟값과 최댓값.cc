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
vector<long> maxtree, mintree;

void makemintree(int i) {
    while (i != 1) {
        if (mintree[i / 2] > mintree[i]) mintree[i / 2] = mintree[i];
        i--;
    }
}
void makemaxtree(int i) {
    while (i != 1) {
        if (maxtree[i / 2] < maxtree[i]) maxtree[i / 2] = maxtree[i];
        i--;
    }
}

long getmin(int s, int e) {
    long minres = LONG_MAX;

    while (s <= e) {
        if (s % 2 == 1) {
            minres = min(minres, mintree[s]);
            s++;
        }
        if (e % 2 == 0) {
            minres = min(minres, mintree[e]);
            e--;
        }
        s /= 2;
        e /= 2;
    }

    return minres;
}
long getmax(int s, int e) {
    long maxres = 0;

    while (s <= e) {
        if (s % 2 == 1) {
            maxres = max(maxres, maxtree[s]);
            s++;
        }
        if (e % 2 == 0) {
            maxres = max(maxres, maxtree[e]);
            e--;
        }
        s /= 2;
        e /= 2;
    }

    return maxres;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;

    int treeheight = 0;
    int len = N;
    while (len) {
        len /= 2;
        treeheight++;
    }
    int treesize = int(pow(2, treeheight + 1));
    int startindex = treesize / 2 - 1;
    maxtree.resize(treesize + 1, 0);
    mintree.resize(treesize + 1, LONG_MAX);

    for (int i = startindex + 1; i <= startindex + N; i++) {
        int node;
        cin >> node;
        mintree[i] = node;
        maxtree[i] = node;
    }

    makemintree(treesize - 1);
    makemaxtree(treesize - 1);

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a += startindex;
        b += startindex;
        cout << getmin(a, b) << ' ' << getmax(a, b) << endl;
    }

}