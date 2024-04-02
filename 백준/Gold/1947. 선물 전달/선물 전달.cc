#include <iostream>
#include <algorithm>
using namespace std;

int N;
int mod = 1000000000;
long dp[1000001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;

    dp[1] = 0;
    dp[2] = 1;   

    for (int i = 3; i <= N; i++) {
        dp[i] = (i - 1) * (dp[i - 1] % mod + dp[i - 2] % mod) % mod;
    }

    cout << dp[N];
}