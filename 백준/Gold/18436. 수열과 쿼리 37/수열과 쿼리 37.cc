#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define endl '\n'
#define pll pair<long, long>
using ll = long long;
using namespace std;

int N, M;
vector<pll> tree; // even, odd

void maketree(int i) {
    while (i != 1) {
        tree[i / 2].first += tree[i].first;
        tree[i / 2].second += tree[i].second;
        i--;
    }
}

void change(int index, long val) { 
    long firstdiff = 0, seconddiff = 0;
    if (val % 2 == 0 && tree[index].second) { // 홀 -> 짝 변경
        firstdiff = 1;
        seconddiff = -1;
    }
    else if (val % 2 == 1 && tree[index].first) { // 짝 -> 홀 변경
        firstdiff = -1;
        seconddiff = 1;
    }

    while (index > 0) {
        tree[index].first += firstdiff;
        tree[index].second += seconddiff;
        index /= 2;
    }
}

long getevenodd (int s, int e, int mode) {
    long even = 0, odd = 0;

    while (s <= e) {
        if (s % 2 == 1) {
            even += tree[s].first;
            odd += tree[s].second;
            s++;
        }
        if (e % 2 == 0) {
            even += tree[e].first;
            odd += tree[e].second;
            e--;
        }
        s /= 2;
        e /= 2;
    }

    if (mode == 0) return even;
    else return odd;

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;

    int height = 0;
    int len = N;
    while (len) {
        len /= 2;
        height++;
    }
    int treesize = int(pow(2, height + 1));
    int left = treesize / 2 - 1; 
    tree.resize(treesize + 1);

    for (int i = left + 1; i <= left + N; i++) {
        long node;
        cin >> node;
        if (node % 2 == 0) tree[i] = {1, 0};
        else tree[i] = {0, 1};
    }

    maketree(treesize - 1);

    cin >> M;

    for (int i = 0; i < M; i++) {
        long a, b, c;
        cin >> a >> b >> c;

        if (a == 1) {
            b += left;
            change(b, c);
        }
        else if (a == 2) {
            b += left;
            c += left;
            cout << getevenodd(b, c, 0) << endl;
        }
        else if (a == 3) {
            b += left;
            c += left;
            cout << getevenodd(b, c, 1) << endl;
        }
    }

}