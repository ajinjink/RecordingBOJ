#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#define endl '\n'
#define pii pair<int, int>
using ll = long long;
using namespace std;

vector<ll> tree, lazy, arr;

ll treeinit(int index, int s, int e) {
    if (s == e) return tree[index] = arr[s];
    int mid = (s + e) / 2;
    return tree[index] = treeinit(index * 2, s, mid) ^ treeinit(index * 2 + 1, mid + 1, e);
}

void propagate(int index, int s, int e) {
    if (lazy[index]) {
        if (s != e) {
            lazy[index * 2] ^= lazy[index];
            lazy[index * 2 + 1] ^= lazy[index];
        }

        tree[index] ^= ((e - s + 1) % 2) * lazy[index];
        lazy[index] = 0;
    }
}

void update(int index, int s, int e, int l, int r, ll diff) {
    propagate(index, s, e);

    if (r < s || e < l) return; // 범위 밖
    if (l <= s && e <= r) { // 범위 겹침
        lazy[index] ^= diff;
        propagate(index, s, e);
        return;
    }

    int mid = (s + e) / 2;
    update(index * 2, s, mid, l, r, diff);
    update(index * 2 + 1, mid + 1, e, l, r, diff);
    tree[index] = tree[index * 2] ^ tree[index * 2 + 1];
}

ll getval(int index, int s, int e, int target) {
    propagate(index, s, e);
    
    if (s == e) return tree[index];

    int mid = (s + e) / 2;
    if (target <= mid) return getval(index * 2, s, mid, target);
    else return getval(index * 2 + 1, mid + 1, e, target);
}

ll getres(int index, int s, int e, int l, int r) {
    propagate(index, s, e);
    
    if (r < s || e < l) return 0;
    if (l <= s && e <= r) return tree[index];
    int mid = (s + e) / 2;
    return getres(index * 2, s, mid, l, r) ^ getres(index * 2 + 1, mid + 1, e, l, r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n;
    tree.resize(4 * n + 10); lazy.resize(4 * n + 10); arr.resize(n + 10);

    for (int i = 1; i <= n; i++) cin >> arr[i];
    treeinit(1, 1, n);

    cin >> m;
    for (int i = 0; i < m; i++) {
        int t, a, b, c;
        cin >> t;

        if (t == 1) { // xor c to a~b
            cin >> a >> b >> c;
            a += 1; b += 1;
            update(1, 1, n, a, b, c);
        }
        else {
            cin >> a >> b;
            a++; b++;
            cout << getres(1, 1, n, a, b) << endl;
        }

    }
    
}