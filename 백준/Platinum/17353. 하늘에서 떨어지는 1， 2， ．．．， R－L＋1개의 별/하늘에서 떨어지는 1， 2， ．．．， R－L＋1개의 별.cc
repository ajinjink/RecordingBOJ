#include <iostream>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>
#define endl '\n'
#define pll pair<ll, ll>
using ll = long long;
using namespace std;

int n, q;
ll arr[100010];
ll tree[100010], cnt[100010];

void update(int a, int val) { // a에서 시작해서 모든 하위 노드 +val
    for (int i = a; i <= n; i+= (i & -i)) {
        tree[i] += val;
        if (val > 0) cnt[i]++;
        else cnt[i]--;
    }
}

pll getsum(int a) {
    pll res = {0, 0};
    for (int i = a; i > 0; i -= (i & -i)) {
        res.first += tree[i]; // b 값들의 합
        res.second += cnt[i]; // 몇 번 업데이트 됐는지
    }
    return res;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];

    cin >> q;
    for (int i = 0; i < q; i++) {
        int a, b, c;
        cin >> a;
        
        if (a == 1) { // b~c에 별 떨어짐 1~(c-b+1)
            cin >> b >> c;
            update(b, b);
            update(c + 1, -b);
        }
        else { // b에 떨어진 별 출력
            cin >> b;
            pll count = getsum(b);
            cout << count.second * (b + 1) - count.first + arr[b] << endl;

        }
    }
}