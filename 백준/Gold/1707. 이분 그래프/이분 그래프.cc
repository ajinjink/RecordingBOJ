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

    int K, V, E, a, b;
    cin >> K;
    
    for (int t = 0; t < K; t++) {
        memset(visited, 0, sizeof(visited));
        while (!q.empty()) {
            q.pop();
        }

        cin >> V >> E;

        v.clear();
        v.resize(V + 1);

        for (int i = 0; i < E; i++) {
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }

        bool flag, res = true;
        for (int i = 1; i <= V; i++) {
            if (!visited[i]) {
                flag = bfs(i);
                if (!flag) {
                    res = false;
                    break;
                }
            }
        }
        if (res) {
            cout << "YES" << '\n';
        }
        else {
            cout << "NO" << '\n';
        }
    }
    
}
