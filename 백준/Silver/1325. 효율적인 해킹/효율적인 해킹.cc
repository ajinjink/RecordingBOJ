#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int visited[10001] = {0};
int res[10001] = {0};
vector<vector<int> > v;
queue<int> q;

void bfs(int node) {
    q.push(node);
    while (!q.empty()) {
        int current = q.front();
        visited[current] = 1;
        q.pop();
        for (int i = 0; i < v[current].size(); i++) {
            int next = v[current][i];
            if(!visited[next]) {
                visited[next] = 1;
                res[next]++;
                q.push(next);
            }
            
        }    
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, A, B;
    cin >> N >> M;

    v.resize(N + 1);

    for (int i = 0; i < M; i++) {
        cin >> A >> B;
        v[A].push_back(B);
    }

    for (int i = 1; i <= N; i++) {
        memset(visited, 0, sizeof(visited));
        bfs(i);
    }

    int max = 0;
    for (int i = 1; i <= N; i++) {
        if (res[i] > max) {
            max = res[i];
        }
    }
    for (int i = 1; i <= N; i++) {
        if (res[i] == max) {
            cout << i << ' ';
        }
    }
    
}
