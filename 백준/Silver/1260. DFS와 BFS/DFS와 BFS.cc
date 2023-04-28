#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

bool visited1[1001] = {false};
bool visited2[1001] = {false};
vector<int> graph[1001];

void dfs(int x) {
    visited1[x] = true;
    cout << x << ' ';
    for (int i = 0; i < graph[x].size(); i++) {
        int y = graph[x][i];
        if (!visited1[y]) {
            dfs(y);
        }
    }
}

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited2[start] = true;

    while (!q.empty()) {
        int x = q.front();
        q.pop();
        cout << x << ' ';
        for (int i = 0; i < graph[x].size(); i++) {
            int y = graph[x][i];
            if (!visited2[y]) {
                q.push(y);
                visited2[y] = true;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, V; // 정점의 개수, 간선의 개수, 탐색 시작 정점
    cin >> N >> M >> V;

    int v1, v2;
    for (int i = 0; i < M; i++) {
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    for (int i = 1; i <= N; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    dfs(V);
    cout << '\n';
    bfs(V);
}