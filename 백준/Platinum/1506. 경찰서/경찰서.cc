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
    int N;
    cin >> N;

    adj.resize(N + 1);
    finished.resize(N + 1, false);
    d.resize(N + 1, 0);
    vector<int> cost(N + 1);
    for (int i = 1; i <= N; i++) cin >> cost[i];

    char c;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> c;
            if (c == '1') adj[i].push_back(j);
        }
    }

    for (int i = 1; i <= N; i++) {
        if (!d[i]) dfs(i); // scc 생성
    }

    // 각 scc에 속해있는 도시 중에서 경찰서 최소 비용의 합
    int totalcost = 0;
    for (int i = 0; i < SCC.size(); i++) {
        int mincost = 1000000;
        for (int j = 0; j < SCC[i].size(); j++) {
            mincost = min(mincost, cost[SCC[i][j]]);
        }
        totalcost += mincost;
    }

    cout << totalcost;
}

