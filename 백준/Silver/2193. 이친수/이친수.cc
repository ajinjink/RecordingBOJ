#include <iostream>
#include <algorithm>
using namespace std;

int n;
long dp[91][2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;

    dp[1][1] = 1; // i번째 자리에서 1로 끝나는 이친수 개수
    dp[1][0] = 0; // 0으로 끝나는 이친수 개수

    for (int i = 2; i <= n; i++) {
        dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
        dp[i][1] = dp[i - 1][0];
    }

    cout << dp[n][0] + dp[n][1];

}
