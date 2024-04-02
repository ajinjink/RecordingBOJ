#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int N;
int map[101][101];
int visited[101][101];
int height = 0;
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};

void init() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if  (map[i][j] < height) visited[i][j] = 1;
        }
    }
}

void dfs(int i, int j) {
    if (visited[i][j]) return;
    visited[i][j] = 1;

    for (int k = 0; k < 4; k++) {
        int ni = i + dy[k];
        int nj = j + dx[k];

        if (ni < 0 || ni >= N || nj < 0 || nj >= N) continue;
        if (visited[ni][nj]) continue;
        dfs(ni, nj);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) cin >> map[i][j];
    }

    vector<int> res;

    while (height < 100) {
        height++;
        fill(&visited[0][0], &visited[100][101], 0);
        init();

        int groupcnt = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (!visited[i][j]) {
                    dfs(i, j);
                    groupcnt++;
                }
            }
        }
        if (groupcnt) res.push_back(groupcnt);
        else break;
    }

    sort(res.begin(), res.end(), greater<>());

    cout << res[0];


}