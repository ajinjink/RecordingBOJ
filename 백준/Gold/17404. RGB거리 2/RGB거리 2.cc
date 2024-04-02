#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;

    int R, G, B;

    int cost[1000][3];
    for (int i = 0; i < N; i++) cin >> cost[i][0] >> cost[i][1] >> cost[i][2];

    int res = 1e9;

    for (int start = 0; start < 3; start++) {
        int h[1000][3];
        for (int j = 0; j < 3; j++) {
            if (j == start) h[0][j] = cost[0][j];
            else h[0][j] = 1e9;
        }
        for (int i = 1; i < N; i++) {
            h[i][0] = min(h[i-1][1], h[i-1][2]) + cost[i][0];
            h[i][1] = min(h[i-1][0], h[i-1][2]) + cost[i][1];
            h[i][2] = min(h[i-1][0], h[i-1][1]) + cost[i][2];
        }
        for (int j = 0; j < 3; j++) {
            if (j == start) continue;
            res = min(res, h[N-1][j]);
        }
    }

    cout << res;
}
