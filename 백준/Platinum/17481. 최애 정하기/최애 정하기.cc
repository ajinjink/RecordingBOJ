#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#define endl '\n'
#define pii pair<int, int>
using ll = long long;
using namespace std;

int N, M;
map<string, int> m;
vector<int> g[1001]; // 친구 그래프
vector<int> par(1001, -1); // 멤버 그래프
int visited[1001]; // 친구 visited

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

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        string s;
        cin >> s;

        m[s] = i + 1;
    }

    for (int i = 1; i <= N; i++) {
        int cnt; string s;
        cin >> cnt;

        for (int j = 0; j < cnt; j++) {
            cin >> s;
            g[i].push_back(m[s]);
        }
    }

    int res = 0;
    for (int i = 1; i <= N; i++) {
        fill(&visited[0], &visited[1001], 0);
        res += match(i);
    }

    if (res == N) cout << "YES";
    else cout << "NO\n" << res;

    
}