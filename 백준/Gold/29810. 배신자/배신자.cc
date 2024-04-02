#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

vector<vector<int> > adj;
int visited[200001] = {0};
int cnt = 0, tcnt = 0;
int gnum = 1;
vector<int> gsize;

void dfs(int now) {
    visited[now] = gnum;
    cnt++;
    gsize[gnum]++;
    for (int next : adj[now]) {
        if (!visited[next]) dfs(next);
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    gsize.resize(N + 1, 0);

    adj.resize(N + 1);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int traitor;
    cin >> traitor;

    visited[traitor] = 1;
    for (int f : adj[traitor]) { // 배신자 그룹 쪼개기
        if (!visited[f]) {
            cnt = 0;
            gnum++;
            dfs(f);
        }
    }

    vector<int> temp(gnum + 1, 0);
    for (int f : adj[traitor]) temp[visited[f]]++;
    for (int g = 1; g <= gnum; g++) { // 배신자 친구가 사이클이 아니면
        if (temp[g] == 1) gsize[g]++; // 배신자 추가
    }


    for (int i = 1; i <= N; i++) { // 나머지 그룹 크기 카운트
        if (!visited[i]) {
            cnt = 0;
            gnum++;
            dfs(i);
            gsize.push_back(cnt);
        }
    }

    sort(gsize.begin(), gsize.end());
    cout << gsize[gsize.size() - 1];

}
