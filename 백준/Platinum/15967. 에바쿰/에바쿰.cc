#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
#define pii pair<int, int>
using ll = long long;
using namespace std;

vector<ll> tree, lazy, arr;

ll treeinit(int index, int s, int e) {
    if (s == e) return tree[index] = arr[s];
    int mid = (s + e) / 2;
    return tree[index] = treeinit(index * 2, s, mid) + treeinit(index * 2 + 1, mid + 1, e);
}

void propagate(int index, int s, int e) {
    if (lazy[index]) {
        if (s != e) {
            lazy[index * 2] += lazy[index];
            lazy[index * 2 + 1] += lazy[index];
        }
        tree[index] += (e - s + 1) * lazy[index];
        lazy[index] = 0;
    }
}

void update(int index, int s, int e, int l, int r, ll diff) {
    propagate(index, s, e);

    if (r < s || e < l) return;
    if (l <= s && e <= r) {
        lazy[index] += diff;
        propagate(index, s, e);
        return;
    }

    int mid = (s + e) / 2;
    update(index * 2, s, mid, l, r, diff);
    update(index * 2 + 1, mid + 1, e, l, r, diff);
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
    
    int n, q1, q2;
    cin >> n >> q1 >> q2;
    arr.resize(n + 10);
    tree.resize(4 * n + 10);
    lazy.resize(4 * n + 10);

    for (int i = 1; i <= n; i++) cin >> arr[i];
    treeinit(1, 1, n);

    for (int i = 0; i < q1 + q2; i++) {
        int a, b, c, d;
        cin >> a;

        if (a == 1) { // sum(b, c)
            cin >> b >> c;
            b = min(b, c); c = max(b, c);
            cout << getsum(1, 1, n, b, c) << endl;
        }
        else { // add d to b~c
            cin >> b >> c >> d;
            b = min(b, c); c = max(b, c);
            update(1, 1, n, b, c, d);
        }
    }
    
}