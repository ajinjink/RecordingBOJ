#include <iostream>
#include <queue>
using namespace std;

int volume[3] = {0};
int now[3] = {0};
bool res[201] = {0};
int from[6] = {0, 0, 1, 1, 2, 2};
int to[6] = {1, 2, 0, 2, 0, 1};
int visited[201][201] = {0,};

void bfs() {
    queue<pair<int, int> > q;
    q.push(make_pair(0, 0));
    visited[0][0] = 1;
    res[volume[2]] = 1;

    while (!q.empty()) {
        int A = q.front().first;
        int B = q.front().second;
        int C = volume[2] - A - B;
        q.pop();
        now[0] = A; now[1] = B; now[2] = C;

        for (int i = 0; i < 6; i++) {
            int next[3] = {A, B, C};

            if (now[from[i]] + now[to[i]] <= volume[to[i]]) {
                next[from[i]] = 0;
                next[to[i]] = now[from[i]] + now[to[i]];
            }
            else {
                next[to[i]] = volume[to[i]];
                next[from[i]] = now[from[i]] - (volume[to[i]] - now[to[i]]);
            }

            if (!visited[next[0]][next[1]]) {
                visited[next[0]][next[1]] = 1;
                q.push(make_pair(next[0], next[1]));
            }
            if (next[0] == 0) {
                res[next[2]] = 1;
            }

        }
    }
    

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 3; i++) {
        cin >> volume[i];
    }
    now[2] = volume[2];

    bfs();

    for (int i = 0; i <= volume[2]; i++) {
        if (res[i]) {
            cout << i << ' ';
        }
    }
}