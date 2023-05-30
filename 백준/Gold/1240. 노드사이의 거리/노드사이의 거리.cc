#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

vector<pair<int, int> > v[1001];
int visited[1001] = {0};
int start, finish;
queue<int> q;


void bfs() {
    while (!q.empty()) {
        int now = q.front();
        q.pop();

        if (now == finish) {
            return;
        }

        for (int i = 0; i < v[now].size(); i++) {
            int next = v[now][i].first;
            if (visited[next] == 0) {
                visited[next] = visited[now] + v[now][i].second;
                q.push(next);
            }
        }


    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, M, a, b, dist;
    cin >> N >> M;

    for (int i = 0; i < N - 1; i++) {
        cin >> a >> b >> dist;
        v[a].push_back(make_pair(b, dist));
        v[b].push_back(make_pair(a, dist));
    }

    for (int i = 0; i < M; i++) {
        cin >> start >> finish;
        q.push(start);
        bfs();
        cout << visited[finish] << '\n';
        memset(visited, 0, sizeof(visited));
        while (!q.empty()) {
            q.pop();
        }
    }
}