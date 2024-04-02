#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        int K;
        cin >> K;

        priority_queue<long long, vector<long long>, greater<long long> > pq;

        for (int i = 0; i < K; i++) {
            int n;
            cin >> n;
            pq.push(n);
        }

        long long res = 0;

        while (pq.size() > 1) {
            long long firstmin = pq.top();
            pq.pop();
            long long secondmin = pq.top();
            pq.pop();
            res += firstmin + secondmin;
            pq.push(firstmin + secondmin);
        }

        cout << res << '\n';

    }
}