#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int N, M;
int original[8][8] = {0,};
int temp[8][8];
int virus[8][8];
int visited[8][8] = {0,};
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};
vector<int> res;

void bfs() {
    memcpy(virus, temp, sizeof(temp));
    queue<pair<int, int> > q;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (virus[i][j] == 2) q.push(make_pair(i, j));
        }
    }

    while (!q.empty()) {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int na = a + dy[i];
            int nb = b + dx[i];

            if (0 <= na && na < N && 0 <= nb && nb < M) {
                if (!virus[na][nb]) {
                    virus[na][nb] = 2; // 바이러스 없으면 바이러스 확산
                    q.push(make_pair(na, nb));
                }
            }
        }
    }

    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!virus[i][j]) count++;
        }
    }
    res.push_back(count);
}

void setWall(int cnt) {
    if (cnt == 3) { // 벽 세 개 세웠으면
        bfs();
        return;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!temp[i][j]) {
                temp[i][j] = 1; // 벽 세워
                setWall(cnt + 1);
                temp[i][j] = 0;
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
        for (int j = 0; j < M; j++) {
            cin >> original[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!original[i][j]) { // 0이면
                memcpy(temp, original, sizeof(original));
                temp[i][j] = 1; // 벽 하나 세우고
                setWall(1); // 하나 세웠음. 나머지 벽 세워
                temp[i][j] = 0; // 원상 복구
            }
        }
    }
    
    sort(res.begin(), res.end());
    cout << res[res.size() - 1];


}