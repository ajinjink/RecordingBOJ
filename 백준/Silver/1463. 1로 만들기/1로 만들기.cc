#include <iostream>
#include <algorithm>
using namespace std;

int dp[1000001] = {0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    dp[1] = 0;
    for (int i = 2; i <= N; i++) { // i에서 1까지 가는데 필요한 계산 횟수
        dp[i] = dp[i - 1] + 1;
        if (i % 2 == 0) dp[i] = min(dp[i], dp[i / 2] + 1);
        if (i % 3 == 0) dp[i] = min(dp[i], dp[i / 3] + 1);
    }

    cout << dp[N];
}