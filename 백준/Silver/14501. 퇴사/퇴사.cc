#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define endl '\n'
#define pii pair<int, int>
using ll = long long;
using namespace std;

int n;
int arr[16][2];
int dp[17] = {0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;

    for (int i = 0; i < n; i++) {
        int t, p; // 걸리는 시간, 금액
        cin >> t >> p;
        arr[i][0] = t;
        arr[i][1] = p;
    }

    for (int i = n - 1; i >= 0; i--) {
        if (arr[i][0] + i > n) dp[i] = dp[i + 1];
        else dp[i] = max(arr[i][1] + dp[i + arr[i][0]], dp[i + 1]);
    }

    cout << dp[0];

}
