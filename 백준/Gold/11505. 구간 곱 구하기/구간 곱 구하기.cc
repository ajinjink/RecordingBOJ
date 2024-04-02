#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define endl '\n'
#define pii pair<int, int>
using ll = long long;
using namespace std;

int N, M, K;
vector<long> tree;
static int MOD = 1000000007;

void maketree(int i) {
    while (i != 1) {
        tree[i / 2] = tree[i / 2] * tree[i] % MOD;
        i--;
    }
}

void change(int index, int val) {
    tree[index] = val;

    while (index > 1) {
        index = index / 2;
        tree[index] = (tree[index * 2] % MOD * tree[index * 2 + 1] % MOD) % MOD;
    }
}

long getmul(int s, int e) {
    long res = 1;

    while (s <= e) {
        if (s % 2 == 1) {
            res = res * tree[s] % MOD;
            s++;
        }
        if (e % 2 == 0) {
            res = res * tree[e] % MOD;
            e--;
        }

        s /= 2;
        e /= 2;
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> K;

    int treeheight = 0;
    int len = N;
    while (len) { // 트리 높이 구하기
        len /= 2;
        treeheight++;
    }
    int treesize = int(pow(2, treeheight + 1)); // 트리 크기
    int startindex = treesize / 2 - 1;
    tree.resize(treesize + 1, 1);

    for (int i = startindex + 1; i <= startindex + N; i++) cin >> tree[i];

    maketree(treesize - 1);

    for (int i = 0; i < M + K; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1) change(startindex + b, c);
        else if (a == 2) {
            b += startindex;
            c += startindex;
            cout << getmul(b, c) << endl;
        }
    }   
}