#include <iostream>
#include <string>
#include <cstring>
using namespace std;

string s; 
bool isPalin[2503][2503];
int dp[2503];

int main() {
    cin >> s;
    int n = s.size();
    s = " " + s;
    for (int i = 1; i <= n; i++) isPalin[i][i] = true; // 길이 1짜리
    for (int i = 1; i < n; i++) isPalin[i][i + 1] = (s[i] == s[i + 1]); // 길이 2짜리
    for (int j = 2; j < n; j++) { // j = 길이. 길이 점점 증가시키면서 팔린드롬 양옆에 붙은 것 포함해도 팔린드롬인지 판별
        for (int i = 1; i + j <= n; i++) {
            if (s[i] == s[i + j] && isPalin[i + 1][i + j - 1]) isPalin[i][i + j] = 1;
        }
    }

    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = 1e9;
        for (int j = 1; j <= i; j++) {
            if (isPalin[j][i]) dp[i] = min(dp[i], dp[j - 1] + 1);
        }
    }
    
    cout << dp[n];
}