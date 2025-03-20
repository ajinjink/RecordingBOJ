#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> board)
{
    int res = 0;
    vector<vector<int>> dp(board.size(), vector<int>(board[0].size(), 0));
    for (int i = 0; i < board.size(); i++) {
        if (board[i][0]) {
            dp[i][0] = 1;
            res = 1;
        }
    }
    for (int j = 0; j < board[0].size(); j++) {
        if (board[0][j]) {
            dp[0][j] = 1;
            res = 1;
        }
    }
    for (int i = 1; i < board.size(); i++) {
        for (int j = 1; j < board[0].size(); j++) {
            if (board[i][j] == 0) continue;
            dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
            res = max(res, dp[i][j]*dp[i][j]);
        }
    }
    return res;
}