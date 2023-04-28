#include <iostream>
#include <queue>
using namespace std;

int N, M, H;
int box[101][101][101];
int day[101][101][101] = {0,};
queue<pair<int, pair<int, int> > > q;
int dx[6] = {1, 0, -1, 0, 0, 0};
int dy[6] = {0, 1, 0, -1, 0, 0};
int dh[6] = {0, 0, 0, 0, 1, -1};

void bfs() {

    while (!q.empty()) {
        int h = q.front().first;
        int a = q.front().second.first;
        int b = q.front().second.second;

        q.pop();

        for (int i = 0; i < 6; i++) {
            int nexth = h + dh[i];
            int nexta = a + dx[i];
            int nextb = b + dy[i];
            
            if (0 <= nexta && nexta < N && 0 <= nextb && nextb < M && 0 <= nexth && nexth < H) {
                if (box[nexth][nexta][nextb] == 0) {
                    int nextday = day[h][a][b] + 1;
                    if (day[nexth][nexta][nextb] == 0) {
                        day[nexth][nexta][nextb] = nextday;
                    }
                    else {
                        if (day[nexth][nexta][nextb] > nextday) {
                            day[nexth][nexta][nextb] = nextday;
                        }
                    }

                    q.push(make_pair(nexth, make_pair(nexta, nextb)));
                
                    box[nexth][nexta][nextb] = 1;              
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N >> H;
    int temp;
    for (int h = 0; h < H; h++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> temp;
                box[h][i][j] = temp;
                if (temp == 1) {
                    q.push(make_pair(h, make_pair(i, j)));
                }
            }
        }
    }


    bfs();

    int res = 0;

    for (int h = 0; h < H; h++) {
        for (int i = 0; i  < N; i++) {
            for (int j = 0; j < M; j++) {
                if (day[h][i][j] == 0 && box[h][i][j] == 0) {
                    cout << -1;
                    return 0;
                }
                if (day[h][i][j] > res) {
                    res = day[h][i][j];
                }
            }
        
        }

    }

    cout << res;
}

