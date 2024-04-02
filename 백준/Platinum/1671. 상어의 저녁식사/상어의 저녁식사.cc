#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
vector<int> g[140];
vector<int> par(140, -1);
bool visited[140];
int shark[60][3];

int match(int v) {
    for (auto n : g[v]) {
        if (visited[n]) continue;
        visited[n] = 1;
        if (par[n] == -1 || match(par[n])) {
            par[n] = v; // 먹어
            return 1;
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> shark[i][0] >> shark[i][1] >> shark[i][2];
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if  (i == j) continue;

            if (shark[j][0]==shark[i][0] && shark[j][1]==shark[i][1] && shark[j][2]==shark[i][2]) {
                if (i < j) g[i].push_back(60 + j);
            }
            else if (shark[j][0] <= shark[i][0] && shark[j][1] <= shark[i][1] && shark[j][2] <= shark[i][2]) {
                g[i].push_back(60 + j);
            }
                
        }
    }

    for (int i = 1; i <= N; i++) {
        fill(&visited[0], &visited[141], 0);
        match(i);
        fill(&visited[0], &visited[141], 0);
        match(i);
    }

    int cnt = 0;
    for (int i = 60 + 1; i <= 60 + N; i++) {
        if (par[i] == -1) cnt++;
    }

    cout << cnt;

}