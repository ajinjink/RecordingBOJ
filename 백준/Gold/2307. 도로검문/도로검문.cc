#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<vector<pair<int, int> > > v;
int mindist[1001];
int parent[1001] = {0};

int dijkstra(int n1, int n2) {
    fill(&mindist[0], &mindist[N + 1], 1e9);
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    pq.push(make_pair(0, 1));
    mindist[1] = 0;

    while (!pq.empty()) {
        int now = pq.top().second;
        pq.pop();

        for (pair<int, int> node : v[now]) {
            int next = node.first;
            int pathdist = node.second;

            if (min(now, next) == min(n1, n2) && max(now, next) == max(n1, n2)) continue;

            if (mindist[next] > mindist[now] + pathdist) {
                mindist[next] = mindist[now] + pathdist;
                pq.push(make_pair(mindist[next], next));
                parent[next] = now;
            }
        }

    } 

    return mindist[N];
}



int main() {
    cin >> N >> M;

    v.resize(N + 1);
    for (int i = 0; i < M; i++){
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back(make_pair(b, c));
        v[b].push_back(make_pair(a, c));
    }

    // 일단 최단 거리를 구해 (백트랙킹으로 최단 경로를 구해)
    int mintime = dijkstra(0, 0);
    vector<pair<int, int> > path;
    int child = N;
    while (child != 1) {
        int p = parent[child];
        path.push_back(make_pair(p, child));
        child = p;
    }
    // 최단 경로의 도롤를 하나씩 막으면서 다익스트라
    int maxtime = 0;
    for (int i = 0; i < path.size(); i++) {
        int currtime = dijkstra(path[i].first, path[i].second);
        if (currtime == 1e9) {
            cout << -1;
            return 0;
        }
        maxtime = max(maxtime, currtime);
    }

    cout << maxtime - mintime;

}