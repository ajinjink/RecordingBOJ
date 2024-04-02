#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
#define pii pair<int, int>
using ll = long long;
using namespace std;

int N, root, nodeindex = 1;
int node[10002] = {0}; // 몇 번 등장했는지. 한 번밖에 안 보이면 루트
pii tree[10002]; // left, right
int low[10002], high[10002]; // 인덱스

void dfs(int node, int cnt) {
    // left subtree
    if (tree[node].first > 0) dfs(tree[node].first, cnt + 1);

    low[cnt] = min(low[cnt], nodeindex);
    high[cnt] = max(high[cnt], nodeindex);
    nodeindex++;

    // right subtree
    if (tree[node].second > 0) dfs(tree[node].second, cnt + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        int n, l, r;
        cin >> n >> l >> r;
        node[n]++;
        if (l != -1) node[l]++;
        if (r != -1) node[r]++;
        tree[n] = {l, r};
    }

    for (int i = 1; i <= N; i++) { // 루트 찾기
        if (node[i] == 1) {
            root = i;
            break;
        }
    }

    fill(&low[0], &low[10002], 1e9);

    dfs(root, 1);

    // 최대 길이 구하기
    int res = high[1] - low[1] + 1;
    int level = 1;
    for (int i = 2; i <= N; i++) {
        int temp = high[i] - low[i] + 1;
        if (temp > res) {
            res = temp;
            level = i;
        }
    }
    
    cout << level << ' ' << res;

    
}