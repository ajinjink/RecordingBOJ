// 가장 가까운 공통 조상
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define endl '\n'
#define pii pair<int, int>
using ll = long long;
using namespace std;

int n, m, n1, n2;
vector<vector<int>> v;
bool visited[50001] = {0};
int parent[50001] = {0};
int depth[50001]; // 루트에서 얼마나 떨어져 있나? 같은 레벨의 부모노드 비교

void bfs() {
    visited[1] = true;
    queue<int> q;
    q.push(1);

    while (!q.empty()) {
        int now = q.front();
        q.pop();
        
        for (int i = 0; i < v[now].size(); i++) {
            if (!visited[v[now][i]]) {
                depth[v[now][i]] = depth[now] + 1;
                visited[v[now][i]] = true;
                parent[v[now][i]] = now;
                q.push(v[now][i]);
            }
        }
    }
}

int lca(int a, int b) {
    if (depth[a] > depth[b]) swap(a, b);

    while (depth[a] != depth[b]) b = parent[b];

    while (a != b) {
        a = parent[a];
        b = parent[b];
    }

    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    v.resize(n + 1);
    for (int i = 0; i < n - 1; i++) {
        cin >> n1 >> n2;
        v[n1].push_back(n2);
        v[n2].push_back(n1);
    }

    bfs();

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> n1 >> n2;
        cout << lca(n1, n2) << endl;
    }


}