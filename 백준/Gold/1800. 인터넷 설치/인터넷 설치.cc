/*
이분 탐색을 사용하여 특정한 가격을 넘는 인터넷 선에는 가중치를 부여한다.
따라서 Cost[N]은 1번 컴퓨터에서 N번 컴퓨터를 연결할 때 사용한 인터넷 선 중 특정한 가격이 넘는,
그러니까 무료로 연결해주는 인터넷 선의 개수를 의미한다.
이분 탐색과 다익스트라를 계속 사용하면서 Cost[N]이 K개 이하가 되게 하는 가격 중 최솟값을 찾는다.
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N, P, K;
vector<vector<pair<int, int> > > v;
int cost[1001];
// int parent[1001] = {0};

bool dijkstra(int limit) {
    fill(&cost[0], &cost[N + 1], 1e9);

    cost[1] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    pq.push(make_pair(0, 1));

    while (!pq.empty()) {
        int now = pq.top().second;
        int nowcost = pq.top().first;
        pq.pop();

        for (pair<int, int> node : v[now]) {
            int next = node.first;
            int nextcost = (node.second > limit); // 특정한 가격이 넘으면 카운팅

            if (cost[next] > nowcost + nextcost) {
                cost[next] = nowcost + nextcost;
                pq.push(make_pair(cost[next], next));
                // parent[next] = now;
            }
        }
    }

    return (cost[N] <= K); // 리밋보다 비싼 건 무료로 해 줌. 리밋보다 비싼 게 K개 이하?
    // 리밋보다 비싼 게 K보다 많으면, K개는 무료 처리되고 나머지 중에 제일 비싼 거 돈 내야 함.
    // 리밋보다 비싼 게 K개 이하면, 리밋보다 비싼 거 다 무료 처리 됨.
    // 리밋을 얼마로 설정해야 K개 무료 처리받고 남은 게 가장 쌀까?
    // K개 무료 처리 받으면서 리밋이 작을 수록 좋음.
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> P >> K;

    v.resize(N + 1);

    int maxcost = 0;

    for (int i = 0; i < P; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back(make_pair(b, c));
        v[b].push_back(make_pair(a, c));
        maxcost = max(maxcost, c);
    }

    

    int l = 0, r = maxcost;
    int res = -1; // -1 처리 안 해서 틀렸다아아악
    while (l <= r) {
        int mid = (l + r) / 2;
        if (dijkstra(mid)) {
            res = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }

    cout << res;



}