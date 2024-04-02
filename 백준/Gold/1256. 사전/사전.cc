#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
#define pii pair<int, int>
using ll = long long;
using namespace std;

int n, m, k;
long dp[202][202]; // 남은 총 문자 개수, 남은 z 개수

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m >> k;

    for (int i = 0; i <= 200; i++) { // 조합 테이블 초기화
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) dp[i][j] = 1;
            else {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                if (dp[i][j] > 1000000000) dp[i][j] = 1000000001; // 최대치
            }
        }
    }

    if (dp[n + m][m] < k) { // 주어진 자릿수로 만들 수 없는 k번째 수
        cout << -1;
        return 0;
    }

    while (n || m) {
        if (dp[n - 1 + m][m] >= k) { // k 번째를 넘어감. a
            cout << 'a';
            n--;
        }
        else {
            cout << 'z';
            k -= dp[n - 1 + m][m];
            m--;
        }
    }


}