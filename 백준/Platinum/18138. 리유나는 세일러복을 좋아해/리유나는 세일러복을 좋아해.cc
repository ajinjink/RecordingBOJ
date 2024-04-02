#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
vector<int> g[500];
vector<int> par(500, -1); 
bool visited[500];

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

    cin >> N >> M;

    vector<double> T(N + 1), S(M + 1);
    for (int i = 1; i <= N; i++) cin >> T[i];
    for (int i = 1; i <= M; i++) cin >> S[i];

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (T[i] / 2 <= S[j] && S[j] <= T[i] * 3 / 4) g[i].push_back(250 + j);
            if (T[i] <= S[j] && S[j] <= T[i] * 5 / 4) g[i].push_back(250 + j);
        }
    }

    int res = 0;
    for (int i = 1; i <= N; i++) {
        fill(&visited[0], &visited[501], 0);
        if (match(i)) res++;
    }


    cout << res;
}