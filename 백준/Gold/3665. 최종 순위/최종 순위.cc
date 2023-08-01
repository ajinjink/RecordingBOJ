#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> team(n + 1); // 작년 순위
        vector<int> indegree(n + 1);
        bool ranking[501][501] = {0,};

        for (int i = 1; i <= n; i++) {
            cin >> team[i];
        }
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                ranking[team[i]][team[j]] = true; // i 번째 팀보다 j 번째 팀이 순위가 더 낮았다
                indegree[team[j]]++;
            }
        }

        int m;
        cin >> m;
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;

            if (ranking[a][b]) { // 원래 a가 b보다 앞이었으면
                ranking[a][b] = false; // 순위 변경
                ranking[b][a] = true;
                indegree[b]--;
                indegree[a]++;
            }
            else {
                ranking[b][a] = false; // 순위 변경
                ranking[a][b] = true;
                indegree[a]--;
                indegree[b]++;
            }
        }

        queue<int> q;
        for (int i = 1; i <= n; i++) {
            if (!indegree[i]) {
                q.push(i);
            }
        }

        vector<int> res;
        while (!q.empty()) {
            int now = q.front();
            q.pop();
            res.push_back(now);

            indegree[now]--;

            for (int i = 1; i <= n; i++) {
                if (ranking[now][i]) indegree[i]--; // now가 i보다 먼저면
                if (!indegree[i]) q.push(i);
            }
        }

        if (res.size() == n) {
            for (int i = 0; i < res.size(); i++) {
                cout << res[i] << ' ';
            }
            cout << '\n';
        }
        else {
            cout << "IMPOSSIBLE" << '\n';
        }

        
    }
    
    
}


