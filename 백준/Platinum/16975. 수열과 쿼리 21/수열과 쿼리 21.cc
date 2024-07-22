#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
#define pii pair<int, int>
using ll = long long;
using namespace std;

ll arr[100010], tree[400010];
ll lazy[400010];

ll init(int index, int s, int e) {
    if (s == e) return tree[index] = arr[s];
    int mid = (s + e) / 2;
    return tree[index] = init(index * 2, s, mid) + init(index * 2 + 1, mid + 1, e);
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

void update(int index, int s, int e, int l, int r, int diff) {
    propagate(index, s, e);

    if (r < s || e < l) return; // 범위 밖
    if (l <= s && e <= r) { // 완벽하게 범위 겹침
        lazy[index] += diff;
        propagate(index, s, e);
        return;
    }

    int mid = (s + e) / 2;
    update(index * 2, s, mid, l, r, diff);
    update(index * 2 + 1, mid + 1, e, l, r, diff);
    tree[index] = tree[index * 2] + tree[index * 2 + 1];
}

ll getval(int index, int s, int e, int target) {
    propagate(index, s, e);

    if (s == e) return tree[index];

    int mid = (s + e) / 2;
    if (target <= mid) return getval(index * 2, s, mid, target);
    else return getval(index * 2 + 1, mid + 1, e, target);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n;

    for (int i = 1; i <= n; i++) cin >> arr[i];
    init(1, 1, n);

    cin >> m;
    for (int i = 0; i < m; i++) {
        int q, a, b, k;
        cin >> q;
        if (q == 1) {
            cin >> a >> b >> k;
            update(1, 1, n, a, b, k);
        }
        else {
            cin >> k;
            cout << getval(1, 1, n, k) << endl;
        }
    }

    
}