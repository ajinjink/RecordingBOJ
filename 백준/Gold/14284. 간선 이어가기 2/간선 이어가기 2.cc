#include <iostream>
#include <algorithm>
#include <queue>
#define endl '\n'
#define pii pair<int, int>
using ll = long long;
using namespace std;

int N, M, a, b, c, s, t;
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

    cin >> N >> M;

    v.resize(N + 1);
    fill(&mindist[0], &mindist[5001], 1e9);

    for (int i = 0; i < M; i++){
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }

    cin >> s >> t;

    dijkstra(s);

    cout << mindist[t];
}
