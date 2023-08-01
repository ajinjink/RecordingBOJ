#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        int K, M, P;
        cin >> K >> M >> P;

        vector<vector<int> > v(M + 1);
        vector<int> indegree(M + 1);
        vector<pair<int, int> > res(M + 1);

        for (int i = 0; i < P; i++) {
            int a, b;
            cin >> a >> b;
            v[a].push_back(b);
            indegree[b]++;
        }

        queue<int> q;

        for (int i = 1; i <= M; i++) {
            if (!indegree[i]) {
                q.push(i);
                res[i] = make_pair(1, 1); // 순서, 개수
            }
        }

        while (!q.empty()) {
            int now = q.front();
            q.pop();
            
            for (int i = 0; i < v[now].size(); i++) {
                int next = v[now][i];
                indegree[next]--;

                if (res[next].first < res[now].first) {
                    res[next] = make_pair(res[now].first, 1);
                }
                else if (res[next].first == res[now].first) {
                    res[next].second++;
                }
                if (indegree[next] == 0) {
                    if (res[next].second > 1) {
                        res[next] = make_pair(res[next].first + 1, 1);
                    }
                    q.push(next);
                }
            }
        }

        sort(res.begin(), res.end());

        cout << K << ' ' << res[M].first << '\n';

    }

}