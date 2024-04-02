#include <iostream>
#include <algorithm>
#include <queue>
#define endl '\n'
#define pii pair<int, int>
using ll = long long;
using namespace std;

int N, M, a, b, c;
int visited[50001] = {0};
int mindist[50001];
vector<vector<pii>> v;

void dijkstra() {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 1}); // mindist, node
    mindist[1] = 0;

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
    fill(&mindist[0], &mindist[50001], 1e9);

    for (int i = 0; i < M; i++){
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }

    dijkstra();

    cout << mindist[N];
}
