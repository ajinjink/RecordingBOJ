#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int table[101][101] = {0,};
int visited[101][101] = {0,};
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int M, N, K;
int cnt;
queue<pair<int, int> > q;

void bfs() {
    cnt = 1;

    while (!q.empty()) {
        int a = q.front().first;
        int b = q.front().second;

        visited[a][b] = 1;

        q.pop();

        for (int i = 0; i < 4; i++) {
            int nexta = a + dx[i];
            int nextb = b + dy[i];

            if (0 <= nexta && nexta < N && 0 <= nextb && nextb < M) {
                if (table[nexta][nextb] == 0 && visited[nexta][nextb] == 0) {
                    cnt++;
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

    
    cin >> M >> N >> K;
    

    int bx, by, tx, ty;
    for (int t = 0; t < K; t++) {
        cin >> bx >> by >> tx >> ty;
        for (int i = bx; i < tx; i++) {
            for (int j = by; j < ty; j++) {
                table[i][j] = 1;
            }
        }
    }

    vector<int> field;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (visited[i][j] == 0 && table[i][j] == 0) {
                q.push(make_pair(i, j));
                bfs();
                field.push_back(cnt);
            }
        }
    }

    sort(field.begin(), field.end());
    cout << field.size() << '\n';
    for (int i = 0; i < field.size(); i++) {
        cout << field[i] << ' ';
    }

    
}

