#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int K, N;
    int arr[100];
    priority_queue<long long, vector<long long>, greater<long long> > q;
    map<long long, bool> visited;

    cin >> K >> N;

    for (int i = 0; i < K; i++) {
        cin >> arr[i];
    }

    q.push(1);
    visited[1] = true;
    long long maxnum = 0;

    while (N--) {
        long long now = q.top();
        q.pop();

        for (int i = 0; i < K; i++) {
            long long next = now * arr[i];

            if (visited.count(next)) {  // next 이미 배열에 넣었음
                continue;
            }

            if (q.size() > N && next >= maxnum) { // 큐에 이미 N개 들어왔는데, 최대값보다 크면 N 이후의 수
                continue;
            }

            q.push(next);
            maxnum = max(maxnum, next);
            visited[next] = true;

        }
    }

    cout << q.top();
}

