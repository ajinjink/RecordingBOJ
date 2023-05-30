#include <iostream>
#include <queue>
using namespace std;

int N, K, res;
int visited[100001];
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq; 

void bfs() {
    while (!pq.empty()) {
        int time = pq.top().first; // 시간을 first로 둬서 오름차순. 시간 짧은 것부터 선택
        int now = pq.top().second; // 현재 위치
        pq.pop();
        visited[now] = 1;          // 어차피 한 번 간 곳은 다시 갈 필요 없어. 시간만 더 걸리고 루트는 동일.

        if (now == K) {
            res = time;
            return;
        }

        if (2 * now <= 100000 && !visited[2 * now]) {
            pq.push(make_pair(time, 2 * now));
        }
        if (now - 1 >= 0 && !visited[now - 1]) {
            pq.push(make_pair(time + 1, now - 1));
        }
        if (now + 1 <= 100000 && !visited[now + 1]) {
            pq.push(make_pair(time + 1, now + 1));
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

    cout << res;

}