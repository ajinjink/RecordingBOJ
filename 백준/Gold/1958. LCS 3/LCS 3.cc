#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#define endl '\n'
#define pii pair<int, int>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string A, B, C;
    cin >> A >> B >> C;

    int dp[102][102][102];

    for (int i = 1; i <= A.length(); i++) {
        for (int j = 1; j <= B.length(); j++) {
            for (int k = 1; k <= C.length(); k++) {
                if (A[i - 1] == B[j - 1] && B[j - 1] == C[k - 1]) dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
                else dp[i][j][k] = max(dp[i - 1][j][k], max(dp[i][j - 1][k], dp[i][j][k - 1]));
            }
        }
    }

    cout << dp[A.length()][B.length()][C.length()];
}