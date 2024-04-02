#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define endl '\n'
#define pii pair<int, int>
using ll = long long;
using namespace std;

int arr[301][301] = {0,};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> arr[i][j];
        }
    }

    int k;
    cin >> k;
    while (k--) {
        int i, j, x, y;
        cin >> i >> j >> x >> y;

        int res = 0;
        for (int a = i; a <= x; a++) {
            for (int b = j; b <= y; b++) {
                res += arr[a][b];
            }
        }

        cout << res << endl;
    }

}
