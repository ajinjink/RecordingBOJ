#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
vector<int> g[1001];
vector<int> par(1001, -1);
bool visited[1001];

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

    int T;
    cin >> T;

    while (T--) {
        cin >> N >> M;

        for (int i = 0; i < 1001; i++) g[i].clear();
        par.clear();
        par.resize(1001, -1);
        fill(&visited[0], &visited[1001], 0);

        for (int i = 0; i < M; i++) {
            int a, b;
            cin >> a >> b;
            g[a].push_back(b);
        }

        int res = 0;
        for (int i = 0; i < N; i++) {
            fill(&visited[0], &visited[1001], 0);
            if (match(i)) res++;
        }


        cout << res << '\n';

    }

    
}