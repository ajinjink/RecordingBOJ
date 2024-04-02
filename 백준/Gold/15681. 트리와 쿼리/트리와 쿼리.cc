#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
#define pii pair<int, int>
using ll = long long;
using namespace std;

int n, r, q, tempr;
vector<int> v[100001];
int visited[100001] = {0};
int subcnt[100001];

void dfs(int n, int parent) {
    visited[n] = 1;

    for (auto next : v[n]) {
        if (!visited[next]) dfs(next, n);
    }
    if (parent != -1) subcnt[parent] += subcnt[n];

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> r >> q;

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    fill(&subcnt[0], &subcnt[100001], 1);
    dfs(r, -1);

    for (int i = 0; i < q; i++) {
        cin >> tempr;
        cout << subcnt[tempr] << endl;
    }
    
}
