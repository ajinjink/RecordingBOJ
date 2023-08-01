#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int N, res = 0;
int shark = 2, cnt = 0;
int fx, fy, sx, sy;
int mindist;
int box[20][20] = {0,};
int visited[20][20] = {0,};
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
queue<pair<int, int> > q;

void init() {
    mindist = 10000;
    fx = 25;
    fy = 25;
    while (!q.empty()) q.pop();
    memset(visited, 0, sizeof(visited));
}

void bfs() {
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int a = x + dx[i];
            int b = y + dy[i];

            if (0 <= a && a < N && 0 <= b && b < N && !visited[a][b] && box[a][b] <= shark) {
                if (box[a][b] < shark && box[a][b]) { // 먹을 수 있는 물고기
                    q.push(make_pair(a, b));
                    visited[a][b] = visited[x][y] + 1;
                    if (visited[a][b] < mindist) { // 더 가까워
                        mindist = visited[a][b];
                        fx = a; fy = b;
                    }
                    else if (visited[a][b] == mindist) { // 거리는 같고
                        if (fx == a && fy > b) fy = b; // 가장 위, 왼쪽
                        else if (fx > a) { // 가장 위
                            fx = a;
                            fy = b;
                        }
                    }
                }
                else if (box[a][b] == shark || !box[a][b]) { // 지나가는 칸
                    q.push(make_pair(a, b));
                    visited[a][b] = visited[x][y] + 1;
                }
                
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int temp = 0;

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> box[i][j];
            if (box[i][j] == 9) {
                box[i][j] = 0;
                sx = i; sy = j; // 초기 상어 위치
            }
            if (box[i][j]) temp++;
        }
    }

    if (!temp) {
        cout << 0;
        return 0;
    }

    while (1) {
        init();

        q.push(make_pair(sx, sy));
        visited[sx][sy] = 1; // 초기 거리값이 1이므로 나중에 1 빼야 함
        bfs();

        if (fx < 20 && fy < 20) { // 먹을 수 있는 물고기 찾음
            res += visited[fx][fy] - 1; // 거기까지 가는 거리 더함
            cnt++; // 먹은 물고기 수

            if (cnt == shark) {
                shark++; // 상어 크기 증가
                cnt = 0;
            }

            box[fx][fy] = 0; // 물고기 없어짐

            sx = fx; // 먹은 물고기 위치가
            sy = fy; // 새로운 상어 위치
        }
        else break; // 먹을 수 있는 물고기 없음

    }


    cout << res;
}