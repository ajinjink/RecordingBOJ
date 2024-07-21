#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define endl '\n'
#define pii pair<int, int>
using ll = long long;
using namespace std;

vector<int> A(1000002), B;
vector<ll> tree;

void update(int index, int s, int e, int target, int diff) {
    if (target < s || e < target) return;
    tree[index] += diff;
    if (s == e) return;
    int mid = (s + e) / 2;
    update(index * 2, s, mid, target, diff);
    update(index * 2 + 1, mid + 1, e, target, diff);
}

ll getsum(int index, int s, int e, int l, int r) { // l, r은 s, e가 범위를 넘지 않게 조절
    if (r < s || e < l) return 0;
    if (l <= s && e <= r) return tree[index];
    int mid = (s + e) / 2;
    return getsum(index * 2, s, mid, l, r) + getsum(index * 2 + 1, mid + 1, e, l, r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    B.resize(n + 2);
    tree.resize(4 * n);

    for (int i = 1; i <= n; i++) { // A 몇 번 기계가 몇 번째 인덱스인지
        ll num;
        cin >> num;
        A[num] = i;
    }
    for (int i = 1; i <= n; i++) { // 같은 번호의 기계가 A에서 몇 번째 인덱스인지
        ll num;
        cin >> num;
        B[i] = A[num];
    }

    ll res = 0;
    for (int i = 1; i <= n; i++) {
        int idx = B[i]; // 이 기계가 A에서는 몇 번째 기계인지
        res += getsum(1, 1, n, idx + 1, n); // A에서 이 기계 뒤에 이미 탐색한 기계가 몇 개인지
        // 왜냐하면 지금 B는 순차적으로 1,2,3 번 기계를 탐색 중
        // 근데 대응되는 기계보다 더 뒤에 있는 기계가 이 앞에 있는 B와 이미 짝지어졌으면 교차가 생김
        update(1, 1, n, idx, 1); // A에서 이 기계 이미 탐색 되었다
    }

    cout << res;
}