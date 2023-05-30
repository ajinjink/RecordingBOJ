#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int visited[300001] = {0};
vector<vector<int> > v;
queue<int> q;

void bfs() {
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        for (int i = 0; i < v[current].size(); i++) {
            int next = v[current][i];
            if (visited[next] == 0) {
                visited[next] = visited[current] + 1;
                q.push(next);
            }
        }    
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, K, X, A, B;
    cin >> N >> M >> K >> X;

    v.resize(N + 1);

    for (int i = 0; i < M; i++) {
        cin >> A >> B;
        v[A].push_back(B);
    }

    q.push(X);
    visited[X] = 1;
    bfs();

    bool flag = false;
    for (int i = 1; i <= N; i++) {
        if (visited[i] - 1 == K) {
            cout << i << '\n';
            flag = true;
        }
    }

    if (!flag) {
        cout << -1;
    }
    
}
