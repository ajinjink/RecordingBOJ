#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
#define pii pair<int, int>
using ll = long long;
using namespace std;

int N;
int colors[200001] = {0};
vector<vector<int>> v;
int visited[200001] = {0};
int res = 0;

void dfs(int n, int parentcolor) {
    visited[n] = 1;

    if (parentcolor != -1 && parentcolor != colors[n]) res++;

    for (auto next : v[n]) {
        if (!visited[next]) dfs(next, colors[n]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    v.resize(N + 1);

    for (int i = 1; i <= N; i++) cin >> colors[i];

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    dfs(1, -1);
    
    if (colors[1] != 0) res++;

    cout << res;
}