#include <iostream>
#include <queue>
using namespace std;

int N;
char graph[101][101];
int visited1[101][101] = {0,};
int visited2[101][101] = {0,};
queue<pair<int, int> > q1;
queue<pair<int, int> > q2;
int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};


void bfs1(int i, int j) {
    q1.push(make_pair(i, j));

    while (!q1.empty()) {
        int a = q1.front().first;
        int b = q1.front().second;
        q1.pop();
        visited1[a][b] = 1;
        char current = graph[a][b];

        for (int i = 0; i < 4; i++) {
            int nexta = a + dy[i];
            int nextb = b + dx[i];

            if (nexta >= 0 && nexta < N && nextb >= 0 && nextb < N) {
                if (graph[nexta][nextb] == current && visited1[nexta][nextb] == 0) {
                    q1.push(make_pair(nexta, nextb));
                    visited1[nexta][nextb] = 1;
                }
            }
        }
    }
}

void bfs2(int i, int j) {
    q2.push(make_pair(i, j));
    bool rg = true;
    if (graph[i][j] == 'B') {
        rg = false;
    }

    while (!q2.empty()) {
        int a = q2.front().first;
        int b = q2.front().second;
        q2.pop();
        visited2[a][b] = 1;

        for (int i = 0; i < 4; i++) {
            int nexta = a + dy[i];
            int nextb = b + dx[i];

            if (nexta >= 0 && nexta < N && nextb >= 0 && nextb < N && visited2[nexta][nextb] == 0) {
                if (rg) {
                    if (graph[nexta][nextb] != 'B') {
                        q2.push(make_pair(nexta, nextb));
                        visited2[nexta][nextb] = 1;
                    }
                    

                }
                else { // current == r, g
                    if (graph[nexta][nextb] == 'B') {
                        q2.push(make_pair(nexta, nextb));
                        visited2[nexta][nextb] = 1;
                    }
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> graph[i];
    }

    int normal = 0, weak = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
           
            if (visited1[i][j] == 0) {
                bfs1(i, j);
                normal++;
            }
            if (visited2[i][j] == 0) {
                bfs2(i, j);
                weak++;
            }
        }
    }

    cout << normal << ' ' << weak;



}