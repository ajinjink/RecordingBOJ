#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
#define pii pair<int, int>
using namespace std;

int N, L, R;
int map[51][51];
int visited[51][51] = {0,};
int avg[2501] = {0};
int sum = 0, cnt = 0, gnum = 0;
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};

void bfs(int x, int y) {
    queue<pii> q;
    q.push(make_pair(x, y));

    while (!q.empty()) {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();
        
        visited[a][b] = gnum;
        sum += map[a][b];
        cnt++;

        for (int i = 0; i < 4; i++) {
            int nexta = a + dy[i];
            int nextb = b + dx[i];

            if (nexta >= 0 && nexta < N && nextb >= 0 && nextb < N && !visited[nexta][nextb]) {
                if (L <= abs(map[a][b] - map[nexta][nextb]) && abs(map[a][b] - map[nexta][nextb]) <= R) {
                    visited[nexta][nextb] = gnum;
                    q.push(make_pair(nexta, nextb));
                }
            }
        }

    }
}

bool updatemap(int group, int average) {
    bool diff = false;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (visited[i][j] == group) {
                if (map[i][j] != average) diff = true;
                map[i][j] = average;
            }
        }
    }
    return diff;
}

int main() {

    cin >> N >> L >> R;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }

    int res = 0;
    bool cntday = true;

    while (cntday) {
        fill(&visited[0][0], &visited[50][51], 0);
        fill(&avg[0], &avg[2501],0);
        gnum = 0;
        sum = 0;
        cnt = 0;
        cntday = false;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                sum = 0;
                cnt = 0;
                if (!visited[i][j]) {
                    ++gnum;
                    bfs(i, j);
                    avg[gnum] = sum / cnt;
                }
                
                if (cnt > 1) {
                    bool move = updatemap(gnum, avg[gnum]);
                    if (move) cntday = true;
                }
            }
        }
        
        if (cntday) res++;

    }

    cout << res;

}