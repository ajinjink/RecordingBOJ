#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
#include <limits.h>
using namespace std;

int N, M, K;
vector<vector<pair<int, int> > > v;
long long mindist[10001][21];

void dijkstra() {
    priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int> >, greater<tuple<long long, int, int> > > pq; // mindist, now, cnt
    pq.push(make_tuple(0, 1, 0));
    mindist[1][0] = 0;

    while (!pq.empty()) {
        int now = get<1>(pq.top());
        int cnt = get<2>(pq.top());
        long long cost = get<0>(pq.top());
        pq.pop();

        if (mindist[now][cnt] < cost) continue;

        for (int i = 0; i < v[now].size(); i++) {
            int next = v[now][i].first;
            long long nextcost = cost + v[now][i].second;

            if (mindist[next][cnt] > nextcost) {
                mindist[next][cnt] = nextcost;
                pq.push(make_tuple(mindist[next][cnt], next, cnt));
            }

            if (mindist[next][cnt + 1] > cost && cnt + 1 <= K) {
                mindist[next][cnt + 1] = cost;
                pq.push(make_tuple(cost, next, cnt + 1));
            }
        }
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> K;
    
    v.resize(N + 1);

    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back(make_pair(b, c));
        v[b].push_back(make_pair(a, c));
    }

    fill(&mindist[0][0], &mindist[10000][21], LLONG_MAX);
    dijkstra();

    long long res = LLONG_MAX;
    for (int i = 0; i <= K; i++) {
        res = min(res, mindist[N][i]);
    }
    cout << res;

}