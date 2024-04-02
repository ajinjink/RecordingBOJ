#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int N, M;
int map[101][101]; // 장애물 위치 저장
int group[101][101][2]; // 각 방향 몇 번째 대각선에 속하는지
int dx[2] = {1, -1};
int dy[2] = {1, 1};
int gnum[2] = {1, 1}; // 대각선 번호 카운팅
// 서로 교차하는 대각선 위에 있는 비숍끼리는 잡아먹을 수 없음. 교차를 최대한 많이 하자.
set<int> g[10001]; // 이쪽 대각선이 저쪽 몇 번째 대각선과 교차하는가
int par[10001]; // 저쪽 대각선 occupy
bool visited[10001];

void setgroup(int dir) { // 각 셀이 몇 번째 대각선에 속하는지
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (map[i][j]) continue;
            if (group[i][j][dir]) continue;
            int ni = i, nj = j;
            group[ni][nj][dir] = gnum[dir];
            while (1) {
                ni += dy[dir];
                nj += dx[dir];
                if (ni < 1 || ni > N || nj < 1 || nj > N) break;
                // if (map[ni][nj]) break;
                if (group[ni][nj][dir]) break;
                group[ni][nj][dir] = gnum[dir];
            }
            gnum[dir]++;

        }
    }
}

int match(int v) {
    for (auto n : g[v]) { 
        if (visited[n]) continue;
        visited[n] = 1; 
        if (par[n] == -1 || match(par[n])) {
            par[n] = v;
            return 1;
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int a;
            cin >> a;
            map[i][j] = !a;
        }
    }

    // 각 셀이 몇 번째 대각선에 속하는지
    setgroup(0); // 왼쪽 위에서 오른쪽 아래로 
    setgroup(1); // 오른쪽 위에서 왼쪽 아래로

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (map[i][j]) continue;
            // ex. 이쪽 2번 대각선이랑 저쪽 3번 대각선 교차
            g[group[i][j][0]].insert(group[i][j][1]);
        }
    }

    int res = 0;
    fill(&par[0], &par[10001], -1);
    for (int i = 1; i <= gnum[0]; i++) {
        fill(&visited[0], &visited[10001], 0);
        res += match(i);
    }

    cout << res;

}
