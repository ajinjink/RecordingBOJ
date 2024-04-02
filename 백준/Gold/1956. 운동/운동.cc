#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
#define endl '\n'
#define pii pair<int, int>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int V, E;
    cin >> V >> E;

    long d[401][401];
    fill(&d[0][0], &d[400][401], INT_MAX);
    for (int i = 0; i <= 400; i++) d[i][i] = 0;

    while(E--) {
        int a, b, c;
        cin >> a >> b >> c;
        d[a][b] = c;
    }

    for (int k = 1; k <= V; k++) {
        for (int i = 1; i <= V; i++) {
            for (int j = 1; j <= V; j++) {
                if (d[i][k] + d[k][j] < d[i][j]) d[i][j] = d[i][k] + d[k][j];
            }
        }
    }

    long res = INT_MAX;
    for (int i = 1; i <= V; i++) {
        for (int j = 1; j <= V; j++) {
            if (i == j) continue;
            res = min(res, d[i][j] + d[j][i]);
        }
    }

    if (res == INT_MAX) cout << -1;
    else cout << res;

}