#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int M, N, K;
int map[51][51] = {0,};
int visited[51][51] = {0,};
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
queue<pair<int, int> > q;

void bfs(int i, int j) {
    q.push(make_pair(i, j));

    while (!q.empty()) {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();
        visited[a][b] = 1;

        for (int i = 0; i < 4; i++) {
            int nexta = a + dx[i];
            int nextb = b + dy[i];

            if (nexta >= 0 && nexta < N && nextb >= 0 && nextb < M) {
                if (visited[nexta][nextb] == 0 && map[nexta][nextb] == 1) {
                    q.push(make_pair(nexta, nextb));
                    visited[nexta][nextb] = 1;

                }
            }
        }
    }

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, a, b, res = 0;
    cin >> T;

    for (int t = 0; t < T; t++) {
        cin >> M >> N >> K;
        for (int k = 0; k < K; k++) {
            cin >> b >> a;
            map[a][b] = 1;
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (map[i][j] == 1 && visited[i][j] == 0) {
                    res++;
                    bfs(i, j);
                }
            }
        }

        cout << res << '\n';

  
        memset(map, 0, sizeof(map));
        memset(visited, 0, sizeof(visited));
        res = 0;
    }
}