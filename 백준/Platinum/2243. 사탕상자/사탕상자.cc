#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define endl '\n'
#define pii pair<int, int>
using ll = long long;
using namespace std;

#define MAX 1000001
ll tree[4 * MAX];

void update(int index, int target, int s, int e, int diff) {
    if (target < s || e < target) return;
    tree[index] += diff;
    if (s == e) return;
    int mid = (s + e) / 2;
    update(index * 2, target, s, mid, diff);
    update(index * 2 + 1, target, mid + 1, e, diff);
}

ll query(int index, int s, int e, int cnt) {
    if (s == e) return s;
    int mid = (s + e) / 2;
    if (cnt <= tree[index * 2]) return query(index * 2, s, mid, cnt);
    else return query(index * 2 + 1, mid + 1, e, cnt - tree[index * 2]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    while (n--) {
        int a, b, c;
        cin >> a >> b;
        if (a == 1) {
            int flavor = query(1, 1, MAX, b);
            cout << flavor << endl;
            update(1, flavor, 1, MAX, -1);
        }
        else {
            cin >> c;
            update(1, b, 1, MAX, c);
        }
    }
}