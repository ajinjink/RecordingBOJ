#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define endl '\n'
#define pii pair<int, int>S
using ll = long long;
using namespace std;

int n, k;
int d[1001][1001];
int MOD = 10007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> k;

    for (int i = 0; i <= n; i++) {
        d[i][1] = i;
        d[i][0] = 1;
        d[i][i] = 1;
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            d[i][j] = (d[i - 1][j] % MOD + d[i - 1][j - 1] % MOD) % MOD;
        }
    }

    cout << d[n][k];
}
