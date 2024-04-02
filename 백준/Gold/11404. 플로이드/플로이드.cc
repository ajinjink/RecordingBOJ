#include <iostream>
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
        int a, b, c;
        cin >> a >> b >> c;
        if (mindist[a][b] > c) mindist[a][b] = c;
    }

    for (int k = 1; k <= N; k++) { // floyd-warshall
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (mindist[i][j] > mindist[i][k] + mindist[k][j]) {
                    mindist[i][j] = mindist[i][k] + mindist[k][j];
                }
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (mindist[i][j] == 1e9) cout << "0 ";
            else cout << mindist[i][j] << ' ';
        }
        cout << '\n';
    }

}