#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

int N, M, X;
typedef pair<int, int> Node;
vector<vector<Node> > v[2]; // 역방향 후 X에서 출발, 정방향 후 X에서 출발
vector<int> visited;
vector<int> mindist[2]; // toX, fromX

void dijkstra(int mode) {
    mindist[mode][X] = 0;
    priority_queue<Node, vector<Node>, greater<Node> > pq;
    pq.push(make_pair(0, X));

    while (!pq.empty()) {
        int curr = pq.top().second;
        pq.pop();

        if (visited[curr]) continue;
        else visited[curr] = 1;

        for (int i = 0; i < v[mode][curr].size(); i++) {
            int next = v[mode][curr][i].first;
            int path = v[mode][curr][i].second;

            if (mindist[mode][next] > mindist[mode][curr] + path) {
                mindist[mode][next] = mindist[mode][curr] + path;
                pq.push(make_pair(mindist[mode][next], next));
            }
        }
    }
    
}

int main() {
    cin >> N >> M >> X;

    v[0].resize(N + 1);
    v[1].resize(N + 1);
    visited.resize(N + 1, 0);
    mindist[0].resize(N + 1, INT_MAX);
    mindist[1].resize(N + 1, INT_MAX);

    for (int i = 0; i < M; i++) {
        int start, finish, time;
        cin >> start >> finish >> time;
        v[0][finish].push_back(make_pair(start, time));
        v[1][start].push_back(make_pair(finish, time));
    }

    dijkstra(0); // toX
    visited.clear();
    visited.resize(N + 1, 0);
    dijkstra(1); // fromX

    int res = 0;
    for (int i = 1; i <= N; i++) {
        res = max(res, mindist[0][i] + mindist[1][i]);
    }
    cout << res;
    
}