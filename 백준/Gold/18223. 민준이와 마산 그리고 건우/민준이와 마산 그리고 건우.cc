#include <iostream>
#include <algorithm>
#include <queue>
#define endl '\n'
#define pii pair<int, int>
using ll = long long;
using namespace std;

int V, E, P, a, b, c;
int visited[5001] = {0};
int mindist[5001];
vector<vector<pii>> v;

void dijkstra(int start) {

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, start}); // mindist, node
    mindist[start] = 0;

    while (!pq.empty()) {
        int now = pq.top().second;
        pq.pop();

        if (visited[now]) continue;
        visited[now] = 1;

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

    cin >> V >> E >> P;

    v.resize(V + 1);
    fill(&mindist[0], &mindist[5001], 1e9);

    for (int i = 0; i < E; i++){
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }


    dijkstra(1);
    int S_P = mindist[P]; // start to P
    int S_F = mindist[V]; // start to finish

    fill(&mindist[0], &mindist[5001], 1e9);
    fill(&visited[0], &visited[5001], 0);
    dijkstra(P);

    int P_V = mindist[V];

    if (S_F == S_P + P_V) cout << "SAVE HIM";
    else cout << "GOOD BYE";
}
