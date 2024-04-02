#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

typedef struct Edge {
    int s, e, v;
    bool operator > (const Edge& temp) const {
         return v > temp.v;
    }
} Edge;

static int map[101][101];
static bool visited[101][101] = {false,};
static vector<int> parent;
static int dy[] = {1, -1, 0, 0};
static int dx[] = {0, 0, 1, -1};
int nodenum = 1;
int N, M;
static vector<vector<pair<int, int>>> nodelist;
static vector<pair<int, int>> nodetemp;

void bfs(int i, int j) {
    queue<pair<int, int>> q;
    nodetemp.clear();
    q.push({i, j});
    nodetemp.push_back({i, j});
    visited[i][j] = true;
    map[i][j] = nodenum;

    while (!q.empty()) {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();

        for (int k = 0; k < 4; k++) {
            int na = a + dy[k];
            int nb = b + dx[k];

            if (na >= 0 && na < N && nb >= 0 && nb < M) {
                if (!visited[na][nb] && map[na][nb]) {
                    map[na][nb] = nodenum;
                    visited[na][nb] = true;
                    nodetemp.push_back({na, nb});
                    q.push({na, nb});
                }                
            }
        }
    }
}

int find(int a) {
    if (a == parent[a]) return a;
    else return parent[a] = find(parent[a]);
}

void munion(int a, int b) {
    a = find(a);
    b = find(b);

    if (a != b) parent[b] = a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < N; i++) { // 각 섬 분리
        for (int j = 0; j < M; j++) {
            if (map[i][j] && !visited[i][j]) {
                bfs(i, j);
                nodenum++;
                nodelist.push_back(nodetemp);
            }
        }
    }

    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
    // 만들 수 있는 모든 에지 저장
    for (int i = 0; i < nodelist.size(); i++) {
        vector<pair<int, int>> now = nodelist[i];

        for (int j = 0; j < now.size(); j++) {
            int r = now[j].first;
            int c = now[j].second;
            int nownode = map[r][c];

            for (int k = 0; k < 4; k++) {
                int tempy = dy[k];
                int tempx = dx[k];
                int bridge = 0;

                while (r + tempy >= 0 && r + tempy < N && c + tempx >= 0 && c + tempx < M) {
                    if (map[r + tempy][c + tempx] == nownode) break;
                    else if (map[r + tempy][c + tempx]) { // 같은 섬이 아니고 바다가 아니면
                        if (bridge> 1) pq.push(Edge{nownode, map[r + tempy][c + tempx], bridge});
                        break;
                    }
                    else { // 바다이면 다리 길이 연장하기
                        bridge++;
                    }
                    if (tempy < 0) tempy--;
                    else if (tempy > 0) tempy++;
                    else if (tempx < 0) tempx--;
                    else if (tempx > 0) tempx++;
                }
            }
        }
    }

    parent.resize(nodenum);
    for (int i = 0; i < parent.size(); i++) parent[i] = i;

    int cnt = 0, res = 0;
    while (!pq.empty()) {
        Edge now = pq.top();
        pq.pop();

        if (find(now.s) != find(now.e)) {
            munion(now.s, now.e);
            res += now.v;
            cnt++;
        }
    }

    if (cnt == nodenum - 2) cout << res;
    else cout << -1;
}