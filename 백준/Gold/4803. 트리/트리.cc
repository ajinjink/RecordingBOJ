#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define endl '\n'
#define pii pair<int, int>
using ll = long long;
using namespace std;

int n, m;
int total = 0, cycle = 0;
vector<int> v[501];
int visited[501] = {0};
int parent[501] = {0};
bool node[501] = {0};
int gnum = 1, cnum = 1;

void init() {
    for (int i = 0; i < 501; i++) v[i].clear();
    fill(&visited[0], &visited[501], 0);
    for (int i = 0; i < 501; i++) parent[i] = i;

    total = 0;
    cycle = 0;
    gnum = 1;
    cnum = 1;
}

int find(int n) {
    if (n == parent[n]) return n;

    return parent[n] = find(parent[n]);
}

void union_func(int a, int b) {
    a = find(a);
    b = find(b);

    if (a != b) parent[b] = a; 
}

bool checkset(int a, int b) {
    a = find(a);
    b = find(b);

    if (a == b) return true;
    return false;
}

void bfs(int n, int g) {
    queue<int> q;
    q.push(n);

    while (!q.empty()) {
        int now = q.front();
        q.pop();
        visited[now] = g;

        for (auto next : v[now]) {
            if (!visited[next]) {
                visited[now] = g;
                q.push(next);
            }
        }

    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int casenum = 1;
    
    cin >> n >> m;

    while (n || m) {
        init();

        vector<int> cyclenode;

        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);

            if (!checkset(a, b)) { // 같은 그룹이 아니면
                union_func(a, b);
            }
            else { // 이미 사이클이면
                cyclenode.push_back(a); 
            }
        }

        for (int node : cyclenode) {
            if (!visited[node]) {
                bfs(node, 10000 + cnum);
                cnum++;
                gnum++;
            }
        }

        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                bfs(i, gnum);
                gnum++;
            }
        }
   
        int tree = gnum - cnum;
        if (tree < 0) tree = 0;

        if (tree == 0) cout << "Case " << casenum << ": No trees." << endl;
        else if (tree == 1) cout << "Case " << casenum << ": There is one tree." << endl;
        else cout << "Case " << casenum << ": A forest of " << tree << " trees." << endl;
        casenum++;

        cin >> n >> m;
    }
}