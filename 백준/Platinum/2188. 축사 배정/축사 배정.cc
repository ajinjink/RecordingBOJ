#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
vector<int> g[201]; // 직원 그래프
vector<int> par(201, -1);   // 일 그래프
bool visited[201]; // 일 그래프 visited

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

    for (int i = 1; i <= N; i++) {
        int n;
        cin >> n;

        for (int j = 0; j < n; j++) {
            int a;
            cin >> a;
            g[i].push_back(a);
        }
    }

    int res = 0;
    for (int i = 1; i <= N; i++) {
        fill(&visited[0], &visited[201], 0);
        if (match(i)) res++;
    }


    cout << res;
}