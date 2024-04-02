#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <limits.h>
#define endl '\n'
using ll = long long;
#define pll pair<ll, ll>
using namespace std;

int c, p, pb, pa1, pa2;
vector<vector<pll>> v;
int visited[100001] = {0};
ll mindist[100001];

void dijkstra(int start) {
    priority_queue<pll, vector<pll>, greater<pll>> pq; // dist, node
    pq.push({0, start});
    mindist[start] = 0;

    while (!pq.empty()) {
        int curr = pq.top().second;
        pq.pop();

        if (visited[curr]) continue;
        visited[curr] = 1;

        for (pll node : v[curr]) {
            int next = node.first;
            int cost = node.second;

            if (!visited[next]) {
                if (mindist[next] > mindist[curr] + cost) {
                    mindist[next] = mindist[curr] + cost;
                }
                pq.push({mindist[next], next});
            }
            
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> c >> p >> pb >> pa1 >> pa2;
    v.resize(p + 1);

    for (int i = 0; i < c; i++) {
        int s, e, d;
        cin >> s >> e >> d;
        v[s].push_back({e, d});
        v[e].push_back({s, d});
    }

    fill(&mindist[0], &mindist[100001], INT_MAX);
    dijkstra(pb);
    long d1 = mindist[pa1]; // start to a1
    long d2 = mindist[pa2]; // start to a2

    fill(&visited[0], &visited[100001], 0);
    fill(&mindist[0], &mindist[100001], INT_MAX);
    dijkstra(pa1);
    long d3 = mindist[pa2]; // a1 to a2

    ll res1 = min(d1, d2) * 2 + max(d1, d2);
    ll res2 = min(d1, d2) + d3;

    cout << min(res1, res2);

}
