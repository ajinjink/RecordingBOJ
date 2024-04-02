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

void maketree(int i) {
    while (i != 1) {
        tree[i / 2] = tree[i / 2] * tree[i];
        i--;
    }
}

void change(int index, int val) {
    tree[index] = val;

    while (index > 1) {
        index = index / 2;
        tree[index] = (tree[index * 2] * tree[index * 2 + 1]);
    }
}

long getmul(int s, int e) {
    long res = 1;

    while (s <= e) {
        if (s % 2 == 1) {
            res = res * tree[s];
            s++;
        }
        if (e % 2 == 0) {
            res = res * tree[e];
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

    while (cin >> N >> K) {
        tree.clear();
        
        int treeheight = 0;
        int len = N;
        while (len) { // 트리 높이 구하기
            len /= 2;
            treeheight++;
        }
        int treesize = int(pow(2, treeheight + 1)); // 트리 크기
        int startindex = treesize / 2 - 1;
        tree.resize(treesize + 1, 1);

        for (int i = startindex + 1; i <= startindex + N; i++) {
            int node;
            cin >> node;
            if (node > 0) tree[i] = 1;
            else if (node < 0) tree[i] = -1;
            else tree[i] = 0;
            // cin >> tree[i];
        }

        maketree(treesize - 1);

        for (int i = 0; i < K; i++) {
            char order;
            int a, b;
            cin >> order >> a >> b;

            if (order == 'C') {
                if (b > 0) b = 1;
                else if (b < 0) b = -1;
                change(a + startindex, b);
            }
            else if (order == 'P') {
                a += startindex;
                b += startindex;
                long res = getmul(a, b);
                if (res > 0) cout << '+';
                else if (res < 0) cout << '-';
                else cout << '0';
            }
        }

        cout << endl;

    }
 
}