#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, K;
vector<int> g[501];
vector<int> par(501, -1);
bool visited[501];

int match(int v) {
    if (visited[v]) return 0;
    visited[v] = 1;

    for (auto n : g[v]) {
        if (par[n] == -1 || match(par[n])) {
            par[n] = v;
            return 1;
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    for (int i = 0; i < K; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }

    int res = 0;
    for (int i = 1; i <= N; i++) {
        fill(&visited[0], &visited[502], 0);
        if (match(i)) res++;
    }


    cout << res;
}