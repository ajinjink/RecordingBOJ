#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int R, C;
char map[1001][1001];
int fire[1001][1001];
int mintime[1001][1001];
int visited[1001][1001];
int ji = -1, jj = -1;
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};

void getFireT(int aa, int bb) {
    queue<pair<int, int>> q;
    q.push({aa, bb});
    visited[aa][bb] = 1;
    fire[aa][bb] = 1;

    while (!q.empty()) {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();

        visited[a][b] = 1;

        for (int i = 0; i < 4; i++) {
            int na = a + dy[i];
            int nb = b + dx[i];

            if (na < 0 || na >= R || nb < 0 || nb >= C) continue;
            if (visited[na][nb]) continue;
            if (map[na][nb] == '#') continue;

            if (fire[a][b] + 1 < fire[na][nb]) {
                fire[na][nb] = fire[a][b] + 1;
                visited[na][nb] = 1;
                q.push({na, nb});
            }
                
        }

    }

}

void getMinT() {
    queue<pair<int, int>> q;
    q.push({ji, jj});
    visited[ji][jj] = 1;
    mintime[ji][jj] = 1;

    while (!q.empty()) {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();

        visited[a][b] = 1;

        for (int i = 0; i < 4; i++) {
            int na = a + dy[i];
            int nb = b + dx[i];

            if (na < 0 || na >= R || nb < 0 || nb >= C) continue;
            if (visited[na][nb]) continue;
            if (map[na][nb] == '#') continue;

            mintime[na][nb] = mintime[a][b] + 1;
            visited[na][nb] = 1;
            q.push({na, nb});
        }

    }
}

int main() {
     ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> R >> C;

    vector<pair<int, int>> firearr;

    for (int i = 0; i < R; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < C; j++) {
            map[i][j] = s[j];
            if (map[i][j] == 'J') {
                ji = i; jj = j;
            }
            if (map[i][j] == 'F') {
                firearr.push_back({i, j});
            }
        }
    }

    fill(&fire[0][0], &fire[1000][1001], 1e9);
    for (int i = 0; i < firearr.size(); i++) {
        fill(&visited[0][0], &visited[1000][1001], 0);
        getFireT(firearr[i].first, firearr[i].second);
    }
    
    fill(&visited[0][0], &visited[1000][1001], 0);
    fill(&mintime[0][0], &mintime[1000][1001], -1);
    getMinT();

  
    vector<int> res;
    if (!firearr.size()) { // 만약에 불이 안 났어
        for (int i = 0; i < R; i++) {
            if (map[i][0] != '#' && mintime[i][0] != -1) res.push_back(mintime[i][0]);
            if (map[i][C - 1] != '#' && mintime[i][C - 1] != -1) res.push_back(mintime[i][C - 1]);
        }
        for (int i = 0; i < C; i++) {
            if (map[0][i] != '#' && mintime[0][i] != -1) res.push_back(mintime[0][i]);
            if (map[R - 1][i] != '#' && mintime[R - 1][i] != -1) res.push_back(mintime[R - 1][i]);
        }
        if (res.size()) {
            sort(res.begin(), res.end());
            cout << res[0];
        }
        else cout << "IMPOSSIBLE";

        return 0;
    }


    for (int i = 0; i < R; i++) {
        if (map[i][0] != '#' && mintime[i][0] != -1 && mintime[i][0] < fire[i][0]) res.push_back(mintime[i][0]);
        if (map[i][C - 1] != '#' && mintime[i][C - 1] != -1 && mintime[i][C - 1] < fire[i][C - 1]) res.push_back(mintime[i][C - 1]);
    }
    for (int i = 0; i < C; i++) {
        if (map[0][i] != '#' && mintime[0][i] != -1 && mintime[0][i] < fire[0][i]) res.push_back(mintime[0][i]);
        if (map[R - 1][i] != '#' && mintime[R - 1][i] != -1 && mintime[R - 1][i] < fire[R - 1][i]) res.push_back(mintime[R - 1][i]);
    }

    if (res.size()) {
        sort(res.begin(), res.end());
        cout << res[0];
    }
    else cout << "IMPOSSIBLE";

}