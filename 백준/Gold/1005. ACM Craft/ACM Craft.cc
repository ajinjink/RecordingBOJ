#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define endl '\n'
#define pii pair<int, int>
using ll = long long;
using namespace std;

int N, K;
vector<vector<int>> v;
vector<int> d; // time for construction
vector<int> indegree;
vector<int> res;

void init() {
    v.clear(); v.resize(N + 1);
    d.clear(); d.resize(N + 1);
    indegree.clear(); indegree.resize(N + 1, 0);
    res.clear(); res.resize(N + 1, 0);    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T;
    cin >> T;

    while (T--) {        
        cin >> N >> K;

        init();

        for (int i = 1; i <= N; i++) {
            cin >> d[i];
        }

        for (int i = 0; i < K; i++) {
            int a, b;
            cin >> a >> b;
            v[a].push_back(b);
            indegree[b]++;
        }

        queue<int> q;
        for (int i = 1; i <= N; i++) {
            if (!indegree[i]) {
                q.push(i);
                res[i] = d[i];
            }
        }

        while (!q.empty()) {
            int now = q.front();
            q.pop();

            for (int i = 0; i < v[now].size(); i++) {
                int next = v[now][i];
                indegree[next]--;
                res[next] = max(res[next], res[now] + d[next]);
                if (!indegree[next]) q.push(next);
            }
        }

        int W;
        cin >> W;
        cout << res[W] << endl;

    }
}