#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int> > > v(n + 1);
    vector<vector<pair<int, int> > > reversev(n + 1);
    vector<int> indegree(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b, t;
        cin >> a >> b >> t;

        v[a].push_back(make_pair(b, t));
        reversev[b].push_back(make_pair(a, t));
        indegree[b]++;
    }

    int start, finish;
    cin >> start >> finish;
    queue<int> q;
    q.push(start);
    vector<int> res(n + 1);

    while (!q.empty()) { // 가장 오래 걸리는 시간 찾기
        int now = q.front();
        q.pop();

        for (int i = 0; i < v[now].size(); i++) {
            pair<int, int> next = v[now][i];
            res[next.first] = max(res[next.first], res[now] + next.second); // 그 노드까지 걸리는 최장 시간
            indegree[next.first]--;
            if (!indegree[next.first]) {
                q.push(next.first);
            }
        }
    }

    int count = 0;
    vector<int> visited(n + 1);
    queue<int> rq;
    rq.push(finish); // 도착점에서부터 시작. 역방향
    visited[finish] = 1;

    while (!rq.empty()) {
        int now = rq.front();
        rq.pop();

        for (int i = 0; i < reversev[now].size(); i++) {
            pair<int, int> next = reversev[now][i];
            if (res[next.first] + next.second == res[now]) { // 이 노드가 최장 루트에 포함된다면
                count++;
                if (!visited[next.first]) {
                    visited[next.first] = 1;
                    rq.push(next.first);
                }
            }
        }
    }


    cout << res[finish] << '\n' << count;


}