#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
#define pii pair<int, int>
using ll = long long;
using namespace std;

int N;
vector<int> v[1000001];
int visited[1000001] = {0};
int dp[1000001][2] = {0,};

void dfs(int n) {
    visited[n] = 1;

    dp[n][0] = 1;

    for (int i = 0; i < v[n].size(); i++) {
        int child = v[n][i];
        if (visited[child]) continue;
        dfs(child);
        dp[n][1] += dp[child][0]; // n은 일반인
        dp[n][0] += min(dp[child][0], dp[child][1]); // n이 얼리어답터
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    dfs(1);

    cout << min(dp[1][0], dp[1][1]);
}