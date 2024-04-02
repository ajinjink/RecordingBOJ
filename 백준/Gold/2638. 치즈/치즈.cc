#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int N, M, cnt = 0, res = 0;
int curr[101][101] = {0,};
int nextt[101][101] = {0,};
int visited[101][101] = {0,};
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

void init() {
    queue<pair<int, int> > q;
    q.push(make_pair(0, 0));

    while (!q.empty()) {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();
        visited[a][b] = 1;
        curr[a][b] = -1;


        for (int i = 0; i < 4; i++) {
            int na = a + dy[i];
            int nb = b + dx[i];

            if (0 <= na && na < N && 0 <= nb && nb < M) {
                if (!visited[na][nb]) {
                    if (curr[na][nb] <= 0) {
                        q.push(make_pair(na, nb));
                        visited[na][nb] = 1;
                    }
                }
            }
        }
    }
}

int checkmelt(int i, int j) {
    int sides = 0;
    for (int k = 0; k < 4; k++) {
        int ni = i + dy[k];
        int nj = j + dx[k];
        if (curr[ni][nj] == -1) sides++;
    }
    return sides >= 2;
}

void update(int i, int j) { // 치즈만 탐색
    queue<pair<int, int> > q;
    q.push(make_pair(i, j));

    while (!q.empty()) {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();
        visited[a][b] = 1;
        if (checkmelt(a, b)) {nextt[a][b] = -1; cnt--;} // 녹아
        else nextt[a][b] = 1; // 안 녹아

        for (int k = 0; k < 4; k++) {
            int na = a + dy[k];
            int nb = b + dx[k];
            if (!visited[na][nb] && curr[na][nb] == 1 && 0 < na && na < N && 0 <= nb && nb < M) {
                visited[na][nb] = 1;
                q.push(make_pair(na, nb));
            }
        }
    }
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> curr[i][j];
            if (curr[i][j]) cnt++;
        }
    }


    while (cnt) {
        memset(visited, 0, sizeof(visited));
        init();
        memset(visited, 0, sizeof(visited));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (!visited[i][j] && curr[i][j] == 1) {
                    update(i, j);
                }
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (!visited[i][j]) {
                    nextt[i][j] = curr[i][j];
                }
            }
        }

        res++;
        memcpy(curr, nextt, sizeof(nextt));
    }

    cout << res;

}