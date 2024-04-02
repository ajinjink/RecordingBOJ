#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

vector<vector<int>> adj;
stack<int> s;
vector<int> d; // 부모 노드 저장
vector<bool> finished; // dfs 끝났는지
vector<vector<int>> SCC;
int id = 0;

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
            if (t == now) break; // 스택에서 본인까지 팝. scc 그룹 생성 완료
        }
        SCC.push_back(scctemp);
    }

    return parent;
}

bool compare(vector<int> &a, vector<int> &b) {
    return a[0] < b[0];
}

int main() {
    int N, M;
    cin >> N >> M;
    adj.resize(N + 1);
    finished.resize(N + 1, false);
    d.resize(N + 1, 0);

    int u, v;
    for (int i = 0; i < M; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
    }

    for (int i = 1; i <= N; i++) {
        if (!d[i]) dfs(i); // scc 생성
    }

    if (SCC.size() == 1) cout << "Yes";
    else cout << "No";
}

