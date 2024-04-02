#include <iostream>
#include <algorithm>
#include <queue>
#define endl '\n'
#define pii pair<int, int>
using ll = long long;
using namespace std;

int V, E, P, a, b, c;
int visited[1001] = {0};
int mindist[1001];
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
    fill(&mindist[0], &mindist[1001], 1e9);

    for (int i = 0; i < E; i++){
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }


    dijkstra(P);
    
    int maxdist = 0;
    for (int i = 1; i <= V; i++) maxdist = max(maxdist, mindist[i]);
    cout << maxdist * 2;
}
