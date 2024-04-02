#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int R, C, T;
int room[51][51] = {0,};
int offset[51][51] = {0,};
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};
int r1 = 100, r2 = 100;

void spread(int i, int j) {
    int cnt = 0;
    int amount = room[i][j] / 5;
    for (int k = 0; k < 4; k++) {
        int ni = i + dy[k];
        int nj = j + dx[k];
        if (0 <= ni && ni < R && 0 <= nj && nj < C && room[ni][nj] != -1) {
            offset[ni][nj] += amount;
            cnt += 1;
        }
    }
    room[i][j] -= amount * cnt;
}

void circulate() {
    for (int i = r1 - 1; i > 0; i--) room[i][0] = room[i - 1][0];
    for (int i = 0; i < C - 1; i++) room[0][i] = room[0][i + 1];
    for (int i = i = 0; i < r1; i++) room[i][C - 1] = room[i + 1][C - 1];
    for (int i = C - 2; i > 0; i--) room[r1][i + 1] = room[r1][i];
    room[r1][1] = 0;


    for (int i = r2 +  1; i < R - 1; i++) room[i][0] = room[i + 1][0];
    for (int i = 0; i < C - 1; i++) room[R - 1][i] = room[R - 1][i + 1];
    for (int i = i = R - 1; i > r2; i--) room[i][C - 1] = room[i - 1][C - 1];
    for (int i = C - 2; i > 0; i--) room[r2][i + 1] = room[r2][i];
    room[r2][1] = 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C >> T;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> room[i][j];
            if (room[i][j] == -1) {
                if (r1 == 100) r1 = i;
                else r2 = i;
            }
        }
    }

    while (T--) {
        memset(offset, 0, sizeof(offset));
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (room[i][j] > 0) spread(i, j);
            }
        }
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                room[i][j] += offset[i][j];
            }
        }

        circulate();

    }

    int sum = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (room[i][j] > 0) sum += room[i][j];
        }
    }
    cout << sum;

}