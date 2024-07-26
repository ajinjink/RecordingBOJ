#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
#define pii pair<int, int>
using ll = long long;
using namespace std;

vector<int> tree, lazy, arr;

void propagate(int index, int s, int e) {
    if (lazy[index]) {
        if (s != e) {
            lazy[index * 2] = (lazy[index * 2] + lazy[index]) % 2;
            lazy[index * 2 + 1] = (lazy[index * 2 + 1] + lazy[index]) % 2;
        }
        tree[index] = (e - s + 1) - tree[index];
        lazy[index] = 0;
    }
}

void update(int index, int s, int e, int l, int r) {
    propagate(index, s, e);

    if (r < s || e < l) return;
    if (l <= s && e <= r) {
        lazy[index] = (lazy[index] + 1) % 2;
        propagate(index, s, e);
        return;
    }

    int mid = (s + e) / 2;
    update(index * 2, s, mid, l, r);
    update(index * 2 + 1, mid + 1, e, l, r);
    tree[index] = tree[index * 2] + tree[index * 2 + 1];
}

ll getsum(int index, int s, int e, int l, int r) {
    propagate(index, s, e);
    
    if (r < s || e < l) return 0;
    if (l <= s && e <= r) return tree[index];
    int mid = (s + e) / 2;
    return getsum(index * 2, s, mid, l, r) + getsum(index * 2 + 1, mid + 1, e, l, r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    tree.resize(4 * n + 10); lazy.resize(4 * n + 10); arr.resize(n + 10);

    for (int i = 0; i < m; i++) {
        int o, s, t;
        cin >> o >> s >> t;

        if (o == 0) { // toggle switch s~t
            update(1, 1, n, s, t);
        }
        else { // s~t sum
            cout << getsum(1, 1, n, s, t) << endl;
        }
    }
    
}