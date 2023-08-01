#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<vector<int> > v(N + 1);
    vector<int> indegree(N + 1);

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        indegree[b]++;
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
        cout << now << ' ';
        
        for (int i = 0; i < v[now].size(); i++) {
            int next = v[now][i];
            indegree[next]--;
            if (indegree[next] == 0) {
                q.push(next);
            }
        }
    }
}