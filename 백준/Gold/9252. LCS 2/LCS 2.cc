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
    
    string A, B;
    cin >> A >> B;

    int dp[1002][1002] = {0,};

    for (int i = 1; i <= A.length(); i++) {
        for (int j = 1; j <= B.length(); j++) {
            if (A[i - 1] == B[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    cout << dp[A.length()][B.length()] << endl;

    string cs = "";
    int i = A.length(), j = B.length();
    while (i && j) {
        if (dp[i][j] > dp[i - 1][j] && dp[i - 1][j] == dp[i][j - 1] && dp[i][j - 1] == dp[i - 1][j - 1]) {
            cs += A[i - 1];
            i--;
            j--;
        }
        else if (dp[i - 1][j] == dp[i][j] && dp[i - 1][j] > dp[i][j - 1]) i--;
        else if (dp[i][j - 1] == dp[i][j] && dp[i - 1][j] < dp[i][j - 1]) j--;
        else j--;

    }

    reverse(cs.begin(), cs.end());
    cout << cs;


}