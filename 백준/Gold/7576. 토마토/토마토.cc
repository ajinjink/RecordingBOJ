#include <iostream>
#include <queue>
using namespace std;

int N, M;
int box[1001][1001];
queue<pair<int, int> > q;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};


void bfs() {

    while (!q.empty()) {
        int a = q.front().first;
        int b = q.front().second;

        q.pop();

        for (int i = 0; i < 4; i++) {
            
            int nexta = a + dx[i];
            int nextb = b + dy[i];
            
            if (0 <= nexta && nexta < N && 0 <= nextb && nextb < M) {
                if (box[nexta][nextb] == 0) {
                    
                    
                    q.push(make_pair(nexta, nextb));
                
                    box[nexta][nextb] = box[a][b] + 1;
                }
            }
            
        }

    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> M >> N;
    int temp;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> temp;
            box[i][j] = temp;
            if (temp == 1) {
                q.push(make_pair(i, j));
            }
        }
    }


    bfs();

    int res = 0;

    for (int i = 0; i  < N; i++) {
        for (int j = 0; j < M; j++) {
            if (box[i][j] == 0) {
                cout << -1;
                return 0;
            }
            if (box[i][j] > res) {
                res = box[i][j];
            }
            
        }
        
    }

    cout << res - 1;
}