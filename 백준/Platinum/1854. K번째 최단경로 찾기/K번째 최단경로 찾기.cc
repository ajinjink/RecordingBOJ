#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> Node;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, K;
    cin >> N >> M >> K;
    
    vector<vector<Node > > map(N + 1);
    priority_queue<int> dist[1001];

    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        map[a].push_back(make_pair(b, c));
    }

    priority_queue<Node, vector<Node>, greater<Node> > pq;
    pq.push(make_pair(0, 1));
    dist[1].push(0);

    while (!pq.empty()) {
        int now = pq.top().second;
        int nowdist = pq.top().first;
        pq.pop();

        for (int i = 0; i < map[now].size(); i++) {
            int next = map[now][i].first;
            int cost = nowdist + map[now][i].second;
     
            if (dist[next].size() < K) {
                dist[next].push(cost);
                pq.push(make_pair(cost, next));
            }
            else if (dist[next].top() > cost) {
                dist[next].pop();
                dist[next].push(cost);
                pq.push(make_pair(cost, next));
            }
        }
        
    }

    for (int i = 1; i <= N; i++) {
        if (dist[i].size() == K) cout << dist[i].top() << '\n';
        else cout << -1 << '\n';
    }
    

}