#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N, M;
int map[1001][1001];
int visited[1001][1001] = {0,};
int dy[4] = {-1, 1, 0, 0}; // up, down, left, right
int dx[4] = {0, 0, -1, 1};
int cycle = 0;

void dfs(int y, int x) {
    visited[y][x] = 1; // 1일 때는 사이클 찾는 중
    int ny = y + dy[map[y][x]];
    int nx = x + dx[map[y][x]];

    if (visited[ny][nx] == 1) cycle++; // 사이클 찾음
    else if (visited[ny][nx] == 0) dfs(ny, nx);
    visited[y][x] = 2; // dfs 끝나면 2
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        char c;
        for (int j = 0; j < M; j++) {
            cin >> c;
            if (c == 'U') map[i][j] = 0;
            else if (c == 'D') map[i][j] = 1;
            else if (c == 'L') map[i][j] = 2;
            else if (c == 'R') map[i][j] = 3;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (visited[i][j] == 0) dfs(i, j);
        }
    }

    cout << cycle;
}