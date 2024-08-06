#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
#define pii pair<int, int>
using ll = long long;
using namespace std;

ll arr[100010], tree[400010]; // 초기 별 개수, i-1보다 i번째가 몇 개 더 많은가 (상대적 차이)
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

ll getval(int index, int s, int e, int l, int r) {
    propagate(index, s, e);

    if (r < s || e < l) return 0;
    if (l <= s && e <= r) return tree[index];

    int mid = (s + e) / 2;
    return getval(index * 2, s, mid, l, r) + getval(index * 2 + 1, mid + 1, e, l, r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, q;
    cin >> n;

    for (int i = 1; i <= n; i++) cin >> arr[i];
    for (int i = 1; i <= n; i++) update(1, 1, n, i, i, arr[i] - arr[i - 1]);

    cin >> q;
    for (int i = 0; i < q; i++) {
        int a, b, c;
        cin >> a;

        if (a == 1) { // b~c 별 내림 1~
            cin >> b >> c;
            update(1, 1, n, b, c, 1);
            update(1, 1, n, c + 1, c + 1, -(c - b + 1));

        }
        else { // b 별 개수 출력
            cin >> b;
            cout << getval(1, 1, n, 1, b) << endl;
        }
    }
}