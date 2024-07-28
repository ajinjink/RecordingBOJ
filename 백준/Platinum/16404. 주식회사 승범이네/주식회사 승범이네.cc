#include <iostream>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>
#define endl '\n'
#define pii pair<int, int>
using ll = long long;
using namespace std;

int n, m;
vector<int> tree, in, out; // tree는 본인의 부사수 저장
vector<vector<int>> v;
int cnt = 0;

void dfs(int node) { // 트리에서 노드의 in, out 기록
    in[node] = ++cnt;
    for (int next : v[node]) dfs(next);
    out[node] = cnt;
}

void update(int a, int val) { // a에서 시작해서 관련된 하위 노드(부하) 업뎃
    for (int i = a; i <= n; i+= (i & -i)) tree[i] += val;
}

int getval(int a) {
    int res = 0;
    for (int i = a; i > 0; i -= (i & -i)) res += tree[i];
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    tree.resize(n + 10); in.resize(n + 10); out.resize(n + 10);
    v.resize(n + 10);

    for (int i = 1; i <= n; i++) {
        int s;
        cin >> s;
        if (i != 1) v[s].push_back(i);
    }

    dfs(1);

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a;
        if (a == 1) { // b가 c만큼 칭찬 받음. b와 b의 서브트리에 c 더함
            cin >> b >> c;
            update(in[b], c); // in[b]부터 트리의 끝까지 c가 더해짐
            update(out[b] + 1, -c); // b의 서브트리가 끝나는 지점부터 끝까지 -c
        }
        else { // b의 칭찬 값 출력
            cin >> b;
            cout << getval(in[b]) << endl;
        }
    }
}