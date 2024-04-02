#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
#include <limits.h>
using namespace std;

int N, M;
int map[101][101];
int walls[101][101];
int visited[101][101] = {0};
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};

void dijkstra() {
    walls[0][0] = 0;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int> >, greater<tuple<int, int, int> > > pq;
    pq.push(make_tuple(0, 0, 0));

    while (!pq.empty()) {
        int a = get<1>(pq.top());
        int b = get<2>(pq.top());
        pq.pop();

        for (int i = 0; i < 4; i++) {
            int na = a + dy[i];
            int nb = b + dx[i];
            if (0 <= na && na < N && 0 <= nb && nb < M) {
                int nwalls = walls[a][b] + map[na][nb];
                if (walls[na][nb] > nwalls) {
                    walls[na][nb] = nwalls;
                    pq.push(make_tuple(nwalls, na, nb));
                }
            }
        }

    }
}

int main() {
    cin >> M >> N;

    for (int i = 0; i < N; i++) {
        string temp;
        cin >> temp;
        for (int j = 0; j < M; j++) {
            map[i][j] = temp[j] - '0';
        }
    }

    fill(&walls[0][0], &walls[100][101], INT_MAX);
    dijkstra();

    cout << walls[N - 1][M - 1];

}