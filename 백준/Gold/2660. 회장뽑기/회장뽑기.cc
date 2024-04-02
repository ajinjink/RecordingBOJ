#include <iostream>
#include <algorithm>
using namespace std;

int main() {

    int N;
    cin >> N;

    int mindist[51][51];
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i == j) mindist[i][j] = 0;
            else mindist[i][j] = 1e9;
        }
    }

    int a, b;
    cin >> a >> b;
    while (a != -1 && b != -1) {
        mindist[a][b]  = 1;
        mindist[b][a] = 1;
        cin >> a >> b;
    }

    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (mindist[i][j] > mindist[i][k] + mindist[k][j]) {
                    mindist[i][j] = mindist[i][k] + mindist[k][j];
                }
            }
        }
    }

    int maxdist[51] = {0}; // 최장 거리가 가장 짧은 사람
    int num = 1e9, cnt = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            maxdist[i] = max(maxdist[i], mindist[i][j]);
        }
        if (maxdist[i] < num) {
            num = maxdist[i];
            cnt = 1;
        }
        else if (maxdist[i] == num) cnt += 1;
    }

    cout << num << ' ' << cnt << '\n';
    for (int i = 1; i <= N; i++) {
        if (maxdist[i] == num) {
            cout << i << ' ';
        }
    }
}