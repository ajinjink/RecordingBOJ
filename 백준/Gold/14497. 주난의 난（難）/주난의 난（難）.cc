#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define endl '\n'
#define tiii tuple<int, int, int>
using ll = long long;
using namespace std;

int N, M;
int sx, sy, fx, fy;
char map[300][300];
int visited[300][300] = {0,};
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};
int res = 1e9;

void printvisited() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << visited[i][j] << ' ';
        }
        cout << endl;
    }
}

void bfs() {
    priority_queue<tiii, vector<tiii>, greater<tiii>> pq;
    pq.push({1, sx, sy});
    visited[sx][sy] = 1;

    while (!pq.empty()) {
        int x = get<1>(pq.top());
        int y = get<2>(pq.top());
        int currdist = get<0>(pq.top());
        pq.pop();

        if (x == fx && y == fy) {
            cout << visited[x][y] - 1;
            return;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

            if (visited[nx][ny]) continue;

            if (map[nx][ny] == '0') {
                visited[nx][ny] = visited[x][y];
                pq.push({visited[nx][ny], nx, ny});
            }
            else {
                visited[nx][ny] = visited[x][y] + 1;
                pq.push({visited[nx][ny], nx, ny});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> sx >> sy >> fx >> fy;
    sx--; sy--; fx--; fy--;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < M; j++) {
            map[i][j] = s[j];
        }
    }

    bfs();
    
}