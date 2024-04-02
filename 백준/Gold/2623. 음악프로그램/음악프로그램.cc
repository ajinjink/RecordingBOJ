#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {

    int N, M;
    cin >> N >> M;

    vector<vector<int> > v(N + 1);
    vector<int> indegree(N + 1, 0);
    vector<int> res;

    for (int i = 0; i < M; i++) {
        int cnt, prev, singer;
        cin >> cnt;
        for (int j = 0; j < cnt; j++) {
            cin >> singer;
            if (!j) prev = singer;
            else {
                v[prev].push_back(singer);
                indegree[singer]++;
                prev = singer;
            }
        }
    }

    // for (int i = 1; i <= N; i++) {
    //     cout << i << ": ";
    //     for (int j = 0; j < v[i].size(); j++) {
    //         cout << v[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // for (int i= 1; i <= N; i++) {
    //     cout << indegree[i] << ' ';
    // }

    queue<int> q;

    for (int i = 1; i <= N; i++) {
        if (!indegree[i]) q.push(i);
    }

    while (!q.empty()) {
        int now = q.front();
        q.pop();
        res.push_back(now);

        for (int i = 0; i < v[now].size(); i++) {
            int next = v[now][i];
            indegree[next]--;
            if (!indegree[next]) q.push(next);
        }
    }

    if (res.size() != N) cout << '0';
    else {
        for (int i = 0; i < N; i++) {
            cout << res[i] << '\n';
        }
    }
}