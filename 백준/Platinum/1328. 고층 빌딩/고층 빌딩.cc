#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
#define pii pair<int, int>
using ll = long long;
using namespace std;

int n, l, r;
long mod = 1000000007;
long d[101][101][101]; //[빌딩 개수][왼쪽에서 보이는 개수][오른쪽에서 보이는 개수]일 때 가능한 경우의 수

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> l >> r;

    d[1][1][1] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= l; j++) {
            for (int k = 1; k <= r; k++) {
                d[i][j][k] = ((d[i - 1][j][k - 1] % mod + d[i - 1][j - 1][k] % mod) + (d[i - 1][j][k] * (i - 2)) % mod) % mod;
            }
        }
    }

    cout << d[n][l][r];
}