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

    vector<vector<pair<int, int> > > v(N + 1);
    vector<int> indegree(N + 1);
    vector<int> res(N + 1);

    for (int i = 0; i < M; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        v[x].push_back(make_pair(y, z)); // x를 만드는데 y가 z개 필요
        indegree[y]++;

    }

    queue<int> q;
    q.push(N);
    res[N] = 1;

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        for (int i = 0; i < v[now].size(); i++) {
            pair<int, int> component = v[now][i]; // now를 하나 만드려면 first가 second만큼 필요
            res[component.first] += component.second * res[now];
            
            indegree[component.first]--;
            if (!indegree[component.first]) {
                q.push(component.first);
            }
        }
        if (v[now].size()) {
            res[now] = 0;
        }
    }

    for (int i = 1; i < N; i++) {
        if (res[i] > 0) {
            cout << i << ' ' << res[i] << '\n';
        }
    }
}