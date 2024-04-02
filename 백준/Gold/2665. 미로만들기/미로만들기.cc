#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
#define endl '\n'
#define tiii tuple<int, int, int>
using ll = long long;
using namespace std;

int n;
int map[50][50];
int visited[50][50] = {0,};
int mindist[50][50];
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};

void dijkstra() {
    priority_queue<tiii, vector<tiii>, greater<tiii>> pq; // dist, r, c
    pq.push({0, 0, 0});
    mindist[0][0] = 0;

    while (!pq.empty()) {
        int r = get<1>(pq.top());
        int c = get<2>(pq.top());
        int currdist = get<0>(pq.top());
        pq.pop();

        if (visited[r][c]) continue;
        visited[r][c] = 1;

        for (int i = 0; i < 4; i++) {
            int nextr = r + dy[i];
            int nextc = c + dx[i];
            if (0 <= nextr && nextr < n && 0 <= nextc && nextc < n) {
                if (mindist[nextr][nextc] > mindist[r][c] + map[nextr][nextc]) {
                    mindist[nextr][nextc] = mindist[r][c] + map[nextr][nextc];
                    pq.push({mindist[nextr][nextc], nextr, nextc});
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        string r;
        cin >> r;
        for (int j = 0; j < n; j++) {
            if (r[j] == '0') map[i][j] = 1;
            else map[i][j] = 0;  
        }
    }

    fill(&mindist[0][0], &mindist[49][50], 1e9);
    dijkstra();

    cout << mindist[n - 1][n - 1];

}
