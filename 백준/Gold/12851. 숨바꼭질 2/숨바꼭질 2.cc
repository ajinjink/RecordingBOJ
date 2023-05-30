#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int N, K;
int visited[100001];
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq; 
vector<int> res;
int mintime = 100001;

void bfs() {
    while (!pq.empty()) {
        int time = pq.top().first;
        int now = pq.top().second;
        pq.pop();
        visited[now] = 1;

        if (time > mintime) {
            continue;
        }

        if (now == K) {
            if (time <= mintime) {
                mintime = time;
                res.push_back(time);
            }
        }

        if (2 * now <= 100000 && !visited[2 * now]) {
            pq.push(make_pair(time + 1, 2 * now));
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

    sort(res.begin(), res.end());
    int count = 1;
    for (int i = 1; i < res.size(); i++) {
        if (res[i] == res[0]) {
            count++;
        }
        else {
            break;
        }
    }
    cout << res[0] << '\n' << count;


}