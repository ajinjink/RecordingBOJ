#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int w, h;
    cin >> w >> h;

    while (w != 0 && h != 0) {
        int map[51][51] = {0,};
        int visited[51][51] = {0,};
        int dx[8] = {1, 0, -1, 0, 1, -1, 1, -1};
        int dy[8] = {0, 1, 0, -1, 1, -1, -1, 1};
        int cnt = 0;
        queue<pair<int, int> > q;

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> map[i][j];
            }
        }

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (map[i][j] == 1 && visited[i][j] == 0) {
                    
                    cnt++;
                    // cout << "if. cnt : " << cnt << endl;
                    q.push(make_pair(i, j));

                    while (!q.empty()) {
                        
                        int a = q.front().first;
                        int b = q.front().second;

                        visited[a][b] = 1;

                        // cout << "while. a : " << a << ", b : " << b << endl;

                        q.pop();

                        for (int i = 0; i < 8; i++) {
                            int nexta = a + dx[i];
                            int nextb = b + dy[i];

                            if (0 <= nexta && nexta < h && 0 <= nextb && nextb < w) {
                                if (map[nexta][nextb] == 1 && visited[nexta][nextb] == 0) {
                                    q.push(make_pair(nexta, nextb));
                                    visited[nexta][nextb] = 1;
                                }
                            }
                        }
                    }
                }
            }
            
        }
        cout << cnt << '\n';
        cin >> w >> h;
    }
}