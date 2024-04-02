#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
#include <limits.h>
using namespace std;

int N;
int map[125][125] = {0,};
int mincost[125][125] = {0,};
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

void init() {
    fill(&map[0][0], &map[124][125], 0);
    fill(&mincost[0][0], &mincost[124][125], INT_MAX);
}

void dijkstra() {
    mincost[0][0] = map[0][0];
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int> >, greater<tuple<int, int, int> > > pq;
    pq.push(make_tuple(mincost[0][0], 0, 0));

    while (!pq.empty()) {
        int a = get<1>(pq.top());
        int b = get<2>(pq.top());
        pq.pop();

        for (int i = 0; i < 4; i++) {
            int na = a + dy[i];
            int nb = b + dx[i];
            if (0 <= na && na < N && 0 <= nb && nb < N) {
                if (mincost[na][nb] > mincost[a][b] + map[na][nb]) {
                    mincost[na][nb] = mincost[a][b] + map[na][nb];
                    pq.push(make_tuple(mincost[na][nb], na, nb));
                }
            }
        }
    }


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;

    cin >> N;

    while (N) {
        init();

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> map[i][j];
            }
        }

        dijkstra();

        cout << "Problem " << t++ << ": " << mincost[N - 1][N - 1] << '\n';

        cin >> N;
    }

}