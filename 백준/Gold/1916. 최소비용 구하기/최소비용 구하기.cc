#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

vector<vector<pair<int, int> > > v;
vector<int> dist;
vector<int> visited;

void dijkstra(int begin, int end) {
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    pq.push(make_pair(0, begin));
    dist[begin] = 0;

    while (!pq.empty()) {
        int now = pq.top().second;
        pq.pop();

        if (!visited[now]) {
            visited[now] = 1;

            for (pair<int, int> node : v[now]) {
                if (!visited[node.first] && dist[node.first] > dist[now] + node.second) {
                    dist[node.first] = dist[now] + node.second;
                    pq.push(make_pair(dist[node.first], node.first));
                }
            }
        }
    }

}

int main() {
    int N, M;
    cin >> N >> M;

    v.resize(N + 1);
    dist.resize(N + 1, INT_MAX);
    visited.resize(N + 1, 0);

    for (int i = 0; i < M; i++) {
        int start, finish, fee;
        cin >> start >> finish >> fee;
        v[start].push_back(make_pair(finish, fee));
    }

    int from, to;
    cin >> from >> to;

    dijkstra(from, to);

    cout << dist[to];

}