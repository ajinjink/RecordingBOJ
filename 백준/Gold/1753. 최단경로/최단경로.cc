#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

int main() {
    int V, E, K;
    cin >> V >> E >> K;

    vector<vector<pair<int, int> > > node(V + 1);
    vector<int> mindist(V + 1, INT_MAX);
    vector<int> visited(V + 1, 0);
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        node[u].push_back(make_pair(v, w));
    }

    pq.push(make_pair(0, K));
    mindist[K] = 0;

    while (!pq.empty()) {
        int curr = pq.top().second;
        pq.pop();

        if (visited[curr]) continue;
        else visited[curr] = 1;

        for (int i = 0; i < node[curr].size(); i++) {
            int next = node[curr][i].first;
            int dist = node[curr][i].second;

            if (mindist[next] > mindist[curr] + dist) {
                mindist[next] = mindist[curr] + dist;
                pq.push(make_pair(mindist[next], next));
            }
        }
    }

    for (int i = 1; i <= V; i++) {
        if (visited[i]) cout << mindist[i] << '\n';
        else cout << "INF" << '\n';
    }

}