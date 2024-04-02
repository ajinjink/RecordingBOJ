#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
#define pii pair<int, int>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m, r;
    cin >> n >> m >> r;

    int d[101][101];
    fill(&d[0][0], &d[100][101], 1e9);
    for (int i = 0; i <= 100; i++) d[i][i] = 0;

    int item[101] = {0};
    for (int i = 1; i <= n; i++) cin >> item[i];

    while (r--) {
        int a, b, c;
        cin >> a >> b >> c;
        d[a][b] = d[b][a] = c;
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (d[i][k] + d[k][j] < d[i][j]) d[i][j] = d[i][k] + d[k][j];
            }
        }
    }

    int res = 0;
    for (int i = 1; i <= n; i++) { // i에서 출발 브루트포스
        int cnt = item[i];
        for (int j = 1; j <= n; j++) {
            if (i != j && d[i][j] <= m) {
                cnt += item[j];
            }
        }
        res = max(res, cnt);
    }

    cout << res;

}