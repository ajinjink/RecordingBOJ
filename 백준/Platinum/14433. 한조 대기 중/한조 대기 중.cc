#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
#define pii pair<int, int>
using ll = long long;
using namespace std;

int N, M, K1, K2;
// map<string, int> m;
vector<vector<int>> g(301); // 팀원 그래프
vector<int> par(301, -1); // 캐릭터 그래프
int visited[301]; // 팀원 visited

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
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> K1 >> K2;

    for (int i = 0; i < K1; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }

    int team1 = 0;
    for (int i = 1; i <= N; i++) {
        fill(&visited[0], &visited[301], 0);
        team1 += match(i);
    }

    g.clear();
    g.resize(301);
    par.clear();
    par.resize(301, -1);

    for (int i = 0; i < K2; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }

    int team2 = 0;
    for (int i = 1; i <= N; i++) {
        fill(&visited[0], &visited[301], 0);
        team2 += match(i);
    }

    if (team1 < team2) cout << "네 다음 힐딱이";
    else cout << "그만 알아보자";

}