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
    vector<int> time(N + 1);
    vector<int> res(N + 1);

    for (int i = 1; i <= N; i++) {
        cin >> time[i];

        int temp;
        cin >> temp;
        while (temp != -1) {
            v[temp].push_back(i);
            indegree[i]++;
            cin >> temp;
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
            res[next] = max(res[next], res[now] + time[now]);
            if (indegree[next] == 0) {
                q.push(next);
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << res[i] + time[i] << '\n';
    }
   

}