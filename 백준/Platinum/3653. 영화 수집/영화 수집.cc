#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
#define pii pair<int, int>
using ll = long long;
using namespace std;

vector<ll> tree, idxarr;

void update(int index, int s, int e, int target, int diff) {
    if (target < s || e < target) return;
    tree[index] += diff;
    if (s == e) return;
    int mid = (s + e) / 2;
    update(index * 2, s, mid, target, diff);
    update(index * 2 + 1, mid + 1, e, target, diff);
}

ll getsum(int index, int s, int e, int l, int r) {
    if (r < s || e < l) return 0;
    if (l <= s && e <= r) return tree[index];
    int mid = (s + e) / 2;
    return getsum(index * 2, s, mid, l, r) + getsum(index * 2 + 1, mid + 1, e, l, r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        tree.clear(); tree.resize(4 * (n + m));
        idxarr.clear(); idxarr.resize(n + m + 2);

        for (int i = 1; i <= n; i++) idxarr[i] = m + i; // 몇 번째에 있는지
        
        for (int i = m + 1; i <= m + n; i++) {
            update(1, 1, m + n, i, 1);
        }

        int index = m; // start index 
        // k번째 DVD 빼서 보고, 제일 앞에 넣어
        // idxarr 값을 start index - 1로 저장 
        for (int i = 0; i < m; i++) {
            int k;
            cin >> k;
            cout << getsum(1, 1, m + n, 1, idxarr[k] - 1) << ' ';
            update(1, 1, m + n, idxarr[k], -1); // 빼서 없어짐
            idxarr[k] = index--;
            update(1, 1, m + n, idxarr[k], 1); // 여기다가 넣음
        }

        cout << endl;

    }
}