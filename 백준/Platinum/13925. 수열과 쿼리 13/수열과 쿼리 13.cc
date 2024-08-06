#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
#define pll pair<ll, ll>
using ll = long long;
using namespace std;

const ll MOD = 1e9 + 7;
ll arr[100010], tree[400010];
pll lazy[400010]; // {mul, add}

ll init(int node, int s, int e) {
    if (s == e) return tree[node] = arr[s];
    int mid = (s + e) / 2;
    return tree[node] = (init(node * 2, s, mid) + init(node * 2 + 1, mid + 1, e)) % MOD;
}

void propagate(int node, int s, int e) {
    ll mul = lazy[node].first;
    ll add = lazy[node].second;
    if (mul == 1 && add == 0) return;
    if (s != e) {
        for (int i = node * 2; i <= node * 2 + 1; i++) {
            ll m = lazy[i].first, a = lazy[i].second;
            lazy[i].first = (mul * m); lazy[i].first %= MOD;
            lazy[i].second = ((mul * a) + add); lazy[i].second %= MOD;
        }
    }
    tree[node] = (mul * tree[node] + (e - s + 1) * add); tree[node] %= MOD;
    lazy[node] = {1, 0};
}

void update(int node, int s, int e, int l, int r, ll mul, ll add) {
    propagate(node, s, e);
    if (r < s || e < l) return;
    if (l <= s && e <= r) {
        lazy[node].first *= mul; lazy[node].first %= MOD;
        lazy[node].second *= mul; lazy[node].second %= MOD;
        lazy[node].second += add; lazy[node].second %= MOD;
        propagate(node, s, e);
        return;
    }

    int mid = (s + e) / 2;
    update(node * 2, s, mid, l, r, mul, add);
    update(node * 2 + 1, mid + 1, e, l, r, mul, add);
    tree[node] = (tree[node * 2] + tree[node * 2 + 1]) % MOD;
}

ll getsum(int node, int s, int e, int l, int r) {
    propagate(node, s, e);
    if (r < s || e < l) return 0;
    if (l <= s && e <= r) return tree[node] % MOD;
    int mid = (s + e) / 2;
    return (getsum(node * 2, s, mid, l, r) + getsum(node * 2 + 1, mid + 1, e, l, r)) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    for (int i = 0; i < 400010; i++) lazy[i] = {1, 0};
    init(1, 1, n);

    cin >> m;
    for (int i = 0; i < m; i++) {
        ll a, x, y, v;
        cin >> a >> x >> y;
        if (a == 1) { // + v
            cin >> v;
            update(1, 1, n, x, y, 1, v);
        }
        else if (a == 2) { // * v
            cin >> v;
            update(1, 1, n, x, y, v, 0);
        }
        else if (a == 3) { // == v
            cin >> v;
            update(1, 1, n, x, y, 0, v);
        }
        else { // print
            cout << getsum(1, 1, n, x, y) << endl;
        }
    }

}