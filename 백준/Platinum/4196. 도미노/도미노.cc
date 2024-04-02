#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <cstring>
using namespace std;

int N, M, id = 0;
vector<vector<int> > v; // a
vector<vector<int> > scc;
int indegree[100001] = {0};
int group[100001] = {0};
int d[100001] = {0};
int visited[100001] = {0};
stack<int> s;

void init() {
    id = 0;

    v.clear();
    scc.clear();
    memset(indegree, 0, sizeof(indegree));
    memset(group, 0, sizeof(group));
    memset(d, 0, sizeof(d));
    memset(visited, 0, sizeof(visited));
    while (!s.empty()) s.pop();

    v.resize(N + 1);
    
}

int dfs(int i) {
    d[i] = ++id;
    s.push(i);
    int parent = d[i];

    for (int j = 0; j < v[i].size(); j++) {
        int x = v[i][j];
        if (!d[x]) parent = min(parent, dfs(x));
        else if (!visited[x]) parent = min(parent, d[x]);
    }
    if (parent == d[i]) { // parent가 자신으로 돌아옴
        vector<int> scctemp;
        while (1) {
            int t = s.top();
            s.pop();
            scctemp.push_back(t);
            group[t] = scc.size() + 1; // 몇 번째 그룹
            visited[t] = 1; // scc에 속함
            if (t == i) break; // 스택에서 본인까지 팝. scc 그룹 생성 완료
        }
        scc.push_back(scctemp);
    }

    return parent;
}


int main() {
    int T;
    cin >> T;

    while (T--) {
        cin >> N >> M;

        init();

        for (int i = 0; i < M; i++) {
            int a, b;
            cin >> a >> b;
            v[a].push_back(b);
        }

        for (int i = 1; i <= N; i++) {
            if (!d[i]) dfs(i); // scc 생성
        }

        for (int i = 1; i <= N; i++) {
            for (int j = 0; j < v[i].size(); j++) {
                int x = v[i][j];
                if (group[i] != group[x]) indegree[group[x]] = 1; // i, x 그룹 다르면 진입차수 있음
            }
        }

        int res = 0;
        for (int i = 1; i <= scc.size(); i++) {
            if (!indegree[i]) res++; // 연결이 없음
        }

        cout << res << '\n';

    }
}