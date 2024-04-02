#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

vector<vector<int>> adj;
stack<int> s;
vector<int> d; 
vector<bool> finished; // dfs 끝났는지
vector<int> indegree;
vector<int> group;
vector<vector<int>> SCC;
int id, groupnum;

int dfs(int now) {
    d[now] = ++id; // 노드마다 고유한 번호 할당
    int parent = d[now];
    s.push(now);

    for (int i = 0; i < adj[now].size(); i++) {
        int next = adj[now][i];
        if (!d[next]) parent = min(parent, dfs(next));
        else if (!finished[next]) parent = min(parent, d[next]);

    }

    if (parent == d[now]) { // parent가 자신으로 돌아옴
        vector<int> scctemp;
        while (1) {
            int t = s.top();
            s.pop();
            finished[t] = true; // scc에 속함
            scctemp.push_back(t);
            group[t] = groupnum;
            if (t == now) break; // 스택에서 본인까지 팝. scc 그룹 생성 완료
        }
        SCC.push_back(scctemp);
        groupnum++;
    }

    return parent;
}

void init(int V) {
    adj.clear();
    adj.resize(V + 1);
    while (!s.empty()) s.pop();
    d.clear();
    d.resize(V + 1, 0);
    finished.clear();
    finished.resize(V + 1, false);
    indegree.clear();
    indegree.resize(V + 1, 0);
    group.clear();
    group.resize(V + 1, -1);
    SCC.clear();
    groupnum = 0;
    id = 0;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, M;
        cin >> N >> M;

        init(N);

        int a, b;
        for (int i = 0; i < M; i++) {
            cin >> a >> b;
            adj[a].push_back(b);
        }

        for (int i = 0; i < N; i++) {
            if (!d[i]) dfs(i);
        }

        for (int i = 0; i < N; i++) {
            for (int next : adj[i]) {
                if (group[i] != group[next]) indegree[group[next]]++;
            }
        }

        vector<int> scccnt;
        for (int i = 0; i < SCC.size(); i++) {
            if (!indegree[i]) scccnt.push_back(i);
        }

        if (scccnt.size() != 1) cout << "Confused\n";
        else {
            for (int i = 0; i < N; i++) {
                if (group[i] == scccnt[0]) cout << i << '\n';
            }
        }

        cout << '\n';

    }
}

