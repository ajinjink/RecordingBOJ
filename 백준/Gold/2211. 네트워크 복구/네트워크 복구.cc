#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<vector<pair<int, int> > > v;
int mindist[1001];
int parent[1001] = {0};

void dijkstra() {
    mindist[1] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    pq.push(make_pair(0, 1));

    while (!pq.empty()) {
        int now = pq.top().second;
        pq.pop();

        for (pair<int, int> node : v[now]) {
            int next = node.first;
            int cost = node.second;

            if (mindist[next] > mindist[now] + cost) {
                mindist[next] = mindist[now] + cost;
                pq.push(make_pair(mindist[next], next));
                parent[next] = now;
            }
        }

    }

}

int main() {
    cin >> N >> M;

    v.resize(N + 1);

    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back(make_pair(b, c));
        v[b].push_back(make_pair(a, c));
    }

    fill(&mindist[0], &mindist[N + 1], 1e9);
    dijkstra();

    vector<pair<int, int> > res;
    for (int i = 2; i <= N; i++) {
        if (parent[i]) {
            res.push_back(make_pair(parent[i], i));
        }
    }
    sort(res.begin(), res.end());

    cout << res.size() << '\n';
    for (int i = 0; i < res.size(); i++) {
        cout << res[i].first << ' ' << res[i].second << '\n';
    }
}