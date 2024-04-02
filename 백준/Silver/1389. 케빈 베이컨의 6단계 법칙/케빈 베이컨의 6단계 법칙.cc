#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    int mindist[101][101];

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i == j) mindist[i][j] = 0;
            else mindist[i][j] = 1e9;
        }
    }

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        mindist[a][b] = 1;
        mindist[b][a] = 1;
    }

    for (int k = 1; k <= N; k++) { // floyd-warshall
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (mindist[i][k] + mindist[k][j] < mindist[i][j]) {
                    mindist[i][j] = mindist[i][k] + mindist[k][j];
                }
            }
        }
    }

    int res[101] = {0};
    int minres = 1e9, minuser = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            res[i] += mindist[i][j];
        }
        if (res[i] < minres) {
            minres = res[i];
            minuser = i;
        }
    }

    cout << minuser;
}