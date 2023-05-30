#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int N, K;
int visited[100001];
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq; 
int res = 100001;
int parent[100001];
vector<int> route;

void bfs() {
    while (!pq.empty()) {
        int time = pq.top().first;
        int now = pq.top().second;
        pq.pop();
        visited[now] = 1;

        if (now == K) {
            res = time;

            int index = now;
            while (index != N) {
                route.push_back(index);
                index = parent[index];
            }
            route.push_back(N);

            return;
        }

        if (2 * now <= 100000 && !visited[2 * now]) {
            pq.push(make_pair(time + 1, 2 * now));
            visited[2 * now] = 1;
            parent[2 * now] = now;
        }
        if (now - 1 >= 0 && !visited[now - 1]) {
            pq.push(make_pair(time + 1, now - 1));
            visited[now - 1] = 1;
            parent[now - 1] = now;
        }
        if (now + 1 <= 100000 && !visited[now + 1]) {
            pq.push(make_pair(time + 1, now + 1));
            visited[now + 1] = 1;
            parent[now + 1] = now;
        }
    }
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> K;
    
    pq.push(make_pair(0, N));
    bfs();


    cout << res << '\n';
    for (int i = route.size() - 1; i >= 0; i--) {
        cout << route[i] << ' ';
    }


}