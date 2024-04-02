#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
#define pii pair<int, int>
using ll = long long;
using namespace std;

int N;
vector<vector<int>> tree;
vector<int> visited;
vector<int> parent;

void dfs(int n) {
    visited[n] = 1;

    for (auto next : tree[n]) {
        if (!visited[next]) {
            parent[next] = n;
            dfs(next);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;

    tree.resize(N + 1);
    visited.resize(N + 1);
    parent.resize(N + 1);

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    dfs(1);

    for (int i = 2; i <= N; i++) cout << parent[i] << endl;

    
}