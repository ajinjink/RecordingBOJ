// 이분 그래프

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int visited[20001] = {0};
vector<vector<int> > v;
queue<int> q;

bool bfs(int node) {
    bool flag = true;
    q.push(node);
    visited[node] = 1;
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        for (int i = 0; i < v[current].size(); i++) {
            int next = v[current][i];
            if (visited[next] == visited[current]) {
                flag = false;
            }
            if (visited[current] == 1 && !visited[next]) {
                visited[next] = 2;
                q.push(next);
            }
            if (visited[current] == 2 && !visited[next]) {
                visited[next] = 1;
                q.push(next);
            }
        }    
    }
    return flag;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, a, b;

    cin >> N >> M;

    v.resize(N + 1);

    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    bool flag, res = true;
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            flag = bfs(i);
            if (!flag) {
                res = false;
                break;
            }
        }
    }
    if (res) {
        cout << 1;
    }
    else {
        cout << 0;
    }
    
    
}
