#include <iostream>
#include <queue>
using namespace std;

int N, M;
char maze[101][101];
int visited[101][101];
int dist[101][101];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void BFS(int x, int y) {
    visited[x][y] = 1;

    queue<pair<int, int> > q;
    q.push(make_pair(x, y));

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        for (int i = 0; i < 4; i++) {
            int nextx = x + dx[i];
            int nexty = y + dy[i];

            if (0 <= nextx && nextx < N && 0 <= nexty && nexty < M) {
                if (maze[nextx][nexty] == '1' && visited[nextx][nexty] == 0) {
                    dist[nextx][nexty] = dist[x][y] + 1;
                    visited[nextx][nexty] = 1;
                    q.push(make_pair(nextx, nexty));
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> maze[i];
    }

    BFS(0, 0);
    cout << dist[N - 1][M - 1] + 1;
}