#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define endl '\n'
#define pii pair<int, int>
using ll = long long;
using namespace std;

ll N, Q;
vector<ll> tree;

void maketree(ll i) {
    while (i != 1) {
        tree[i / 2] += tree[i];
        i--;
    }
}

void change(ll index, ll val) { 
    ll diff = val - tree[index];

    while (index > 0) {
        tree[index] = tree[index] + diff;
        index /= 2;
    }
}

ll getsum(ll s, ll e) {
    ll sum = 0;

    while (s <= e) {
        if (s % 2 == 1) {
            sum += tree[s];
            s++;
        }
        if (e % 2 == 0) {
            sum += tree[e];
            e--;
        }
        s /= 2;
        e /= 2;
    }

    return sum;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> Q;

    ll height = 0;
    ll len = N;
    while (len) {
        len /= 2;
        height++;
    }
    ll treesize = pow(2, height + 1);
    ll left = treesize / 2 - 1; 
    tree.resize(treesize + 1);

    for (ll i = left + 1; i <= left + N; i++) cin >> tree[i];

    maketree(treesize - 1);

    for (ll i = 0; i < Q; i++) {
        ll x, y, a, b;
        cin >> x >> y >> a >> b;

        if (x > y) swap(x, y);
        x += left;
        y += left;
        cout << getsum(x, y) << endl;

        change(a + left, b);
    }

}


/* 2프로에서 틀림 */