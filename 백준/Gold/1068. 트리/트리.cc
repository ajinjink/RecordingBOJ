#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
#define pii pair<int, int>
using ll = long long;
using namespace std;

int N, root, del, res = 0;
vector<vector<int>> tree;
vector<int> visited;
vector<int> parent;

void dfs(int n) {
    visited[n] = 1;
    int child = 0;

    for (auto next : tree[n]) {
        if (!visited[next] && next != del) {
            child++;
            dfs(next);
        }
    }

    if (!child) res++;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    tree.resize(N + 1);
    visited.resize(N + 1);
    parent.resize(N + 1);

    for (int i = 0; i < N; i++) {
        int p;
        cin >> p;

        if (p == -1) {
            root = i;
        }
        else {
            tree[i].push_back(p);
            tree[p].push_back(i);
        }
    }

    cin >> del;

    if (del == root) cout << 0;
    else {
        dfs(root);
        cout << res;
    }
    
}