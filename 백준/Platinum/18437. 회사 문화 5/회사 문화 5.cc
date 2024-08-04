#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
#define pii pair<int, int>
using ll = long long;
using namespace std;

int n, m;
vector<ll> tree, lazy, in, out;
vector<vector<int>> v;
int cnt = 0;

void dfs(int now) {
    in[now] = ++cnt;
    for (int next : v[now]) dfs(next);
    out[now] = cnt;
}

void init(int index, int s, int e) {
    if (s == e) {
        tree[index] = 1;
        return;
    }
    int mid = (s + e) / 2;
    init(index * 2, s, mid);
    init(index * 2 + 1, mid + 1, e);
    tree[index] = tree[index * 2] + tree[index * 2 + 1];
}

void propagate(int index, int s, int e) {
    if (lazy[index] != -1) { // -1 indicates no pending update
        tree[index] = lazy[index] * (e - s + 1); // set all values in the range to lazy[index]
        if (s != e) {
            lazy[index * 2] = lazy[index];
            lazy[index * 2 + 1] = lazy[index];
        }
        lazy[index] = -1;
    }
}

void update(int node, int s, int e, int l, int r, ll value) {
    propagate(node, s, e);
    if (r < s || e < l) return;
    if (l <= s && e <= r) {
        tree[node] = value * (e - s + 1);
        if (s != e) {
            lazy[node * 2] = value;
            lazy[node * 2 + 1] = value;
        }
        return;
    }
    int mid = (s + e) / 2;
    update(node * 2, s, mid, l, r, value);
    update(node * 2 + 1, mid + 1, e, l, r, value);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll getsum(int index, int s, int e, int l, int r) {
    propagate(index, s, e);
    if (e < l || r < s) return 0;
    if (l <= s && e <= r) return tree[index];

    int mid = (s + e) / 2;
    return getsum(index * 2, s, mid, l, r) + getsum(index * 2 + 1, mid + 1, e, l, r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    tree.resize(4 * n + 10);
    lazy.resize(4 * n + 10, -1); // Initialize with -1 to indicate no pending update
    in.resize(n + 10);
    out.resize(n + 10);
    v.resize(n + 10);

    for (int i = 1; i <= n; i++) {
        int senior;
        cin >> senior;
        if (i != 1) {
            v[senior].push_back(i);
        }
    }
    dfs(1);

    init(1, 1, n);

    cin >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        if (a == 1) {
            update(1, 1, n, in[b] + 1, out[b], 1);
        }
        else if (a == 2) {
            update(1, 1, n, in[b] + 1, out[b], 0);
        }
        else {
            cout << getsum(1, 1, n, in[b] + 1, out[b]) << endl;
        }
    }
}