#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<vector<int> > v(N + 1);
    vector<int> indegree(N + 1);
    vector<int> worktime(N + 1);
    vector<int> dp(N + 1);

    for (int i = 1; i <= N; i++) {
        int t, num, b;
        cin >> t >> num;

        worktime[i] = t;
        dp[i] = t;

        for (int j = 0; j < num; j++) {
            cin >> b;
            v[b].push_back(i);
            indegree[i]++;
        }
    }

    queue<int> q;

    for (int i = 1; i <= N; i++) {
        if (!indegree[i]) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        for (int i = 0; i < v[now].size(); i++) {
            int next = v[now][i];
            indegree[next]--;
            dp[next] = max(dp[next], dp[now] + worktime[next]);
            if (indegree[next] == 0) {
                q.push(next);
            }
        }
    }

    sort(dp.begin(), dp.end());
    cout << dp[N];
}