#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int N, M, S, V;
vector<int> g[101]; // 들쥐 그래프
vector<int> par(101, -1);   // 땅굴 연결
bool visited[101]; // 들쥐 그래프 visited

double dist(pair<double, double> p1, pair<double, double> p2) {
    double x = fabs(p1.first - p2.first);
    double y = fabs(p1.second - p2.second);
    return x*x + y*y;
}

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

    cin >> N >> M >> S >> V;

    vector<pair<double, double>> mouse(N + 1), hole(M + 1);
    for (int i = 1; i <= N; i++) {
        cin >> mouse[i].first >> mouse[i].second;
    }
    for (int i = 1; i <= M; i++) {
        cin >> hole[i].first >> hole[i].second;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (dist(mouse[i], hole[j]) <= (S*V)*(S*V)) {
                g[i].push_back(j);
            }
        }
    }

    int res = N;
    for (int i = 1; i <= N; i++) {
        fill(&visited[0], &visited[101], 0);
        res -= match(i);
    }

    cout << res;

}