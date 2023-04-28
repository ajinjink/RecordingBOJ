#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, count = 0;
    cin >> N;

    int* dp = new int[N + 1];

    dp[1] = 0;
    dp[2] = 1;

    for (int i = 3; i <= N; i++) {
        dp[i] = dp[i - 1] + 1;

        if (i % 3 == 0) {
            dp[i] = min(dp[i], dp[i/3] + 1);
        }
        
        if (i % 2 == 0) {
            dp[i] = min(dp[i], dp[i/2] + 1);
        }
    }

    cout << dp[N];
    
}
