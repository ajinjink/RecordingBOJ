#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define endl '\n'
#define pii pair<int, int>
using ll = long long;
using namespace std;

vector<ll> tree;

void change(ll index, ll val) { // 트리 값 변경
    ll diff = val - tree[index];

    while (index > 0) {
        tree[index] = tree[index] + diff;
        index /= 2;
    }
}

ll getsum(ll s, ll e) {
    ll sum = 0;

    while (s <= e) {
        if (s % 2 == 1) {
            sum += tree[s];
            s++;
        }
        if (e % 2 == 0) {
            sum += tree[e];
            e--;
        }
        s /= 2;
        e /= 2;
    }

    return sum;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll T;
    cin >> T;

    while (T--) {
        ll B, P, Q;
        cin >> B >> P >> Q;

        tree.clear();

        ll height = 0; // 트리 높이 구하기
        ll len = B;
        while (len) {
            len /= 2;
            height++;
        }

        ll treesize = ll(pow(2, height + 1)); // 원본배열을 리프 노드로 두는 트리 크기
        ll left = treesize / 2 - 1; // 원본 배열 저장 시작 인덱스
        tree.resize(treesize + 1, 0);

        for (ll t = 0; t < P + Q; t++) {
            char c;
            ll i, j;
            cin >> c >> i >> j;

            if (c == 'P') {
                change(left + i, tree[left + i] + j);
            }
            else {
                cout << getsum(left + i, left + j) << endl;
            }
        }

    }
  
}