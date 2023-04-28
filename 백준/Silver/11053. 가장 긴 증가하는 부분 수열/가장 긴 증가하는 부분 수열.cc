#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    int arr[1001];
    int dp[1001] = {0};

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    
    int res = 0;
    for (int i = 1; i <= N; i++) {
        dp[i] = 1;
        for (int j = i - 1; j > 0; j--) {
            if (arr[i] > arr[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        res = max(res, dp[i]);
    }

    cout << res;

}