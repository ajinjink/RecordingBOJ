#include <iostream>
#include <algorithm>
#include <queue>
#define endl '\n'
#define pii pair<int, int>
using ll = long long;
using namespace std;

int V, E, P, a, b, c, t;
int visited[10001] = {0};
int mindist[10001];
vector<vector<pii>> v;
int cnt = 0, maxtime = 0;

void init() {
    fill(&visited[0], &visited[10001], 0);
    fill(&mindist[0], &mindist[10001], 1e9);
    v.clear();
    v.resize(V + 1);
    cnt = 0;
    maxtime = 0;
}

void dijkstra(int start) {

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, start}); // mindist, node
    mindist[start] = 0;

    while (!pq.empty()) {
        int now = pq.top().second;
        pq.pop();

        if (visited[now]) continue;
        visited[now] = 1;
        cnt++;
        maxtime = max(maxtime, mindist[now]);

        for (pii node : v[now]) {
            int next = node.first;
            int cost = node.second;
            if (mindist[next] > mindist[now] + cost) {
                mindist[next] = mindist[now] + cost;
                pq.push({mindist[next], next});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;

    while (t--) {

        cin >> V >> E >> P; // 컴퓨터 수, 엣지 수, 해킹당한 컴퓨터 번호

        init();
        
        for (int i = 0; i < E; i++){
            cin >> a >> b >> c;
            v[b].push_back({a, c});
        }

        dijkstra(P);
        
        cout << cnt << ' ' << maxtime << endl;
    }

}
