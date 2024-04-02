// #include <iostream>
// #include <algorithm>
// #include <vector>
// #define endl '\n'
// using namespace std;

// int N, M;
// int map[1001][1001];
// int visited[1001][1001] = {0,};
// int dy[4] = {0, 0, 1, -1};
// int dx[4] = {1, -1, 0, 0};
// vector<int> res;

// void dfs(int a, int b, int cnt, bool wall) {
//     if (a == N - 1 && b == M - 1) {
//         res.push_back(cnt);
//         return;
//     }

//     visited[a][b] = 1;

//     for (int i = 0; i < 4; i++) {
//         int nexta = a + dy[i];
//         int nextb = b + dx[i];

//         if (nexta < 0 || nexta >= N || nextb < 0 || nextb >= M) continue;
//         if (visited[nexta][nextb]) continue;

//         if (map[nexta][nextb]) { // 다음에 벽
//             if (wall) { // 이미 벽 하나 부숨
//                 continue;
//             }
//             else { // 아직 벽 안 부숨
//                 visited[nexta][nextb] = 1;
//                 dfs(nexta, nextb, cnt + 1, true); // 벽 부수고 가보자
//                 visited[nexta][nextb] = 0;
//             }
//         }
//         else {
//             visited[nexta][nextb] = 1;
//             dfs(nexta, nextb, cnt + 1, wall);
//             visited[nexta][nextb] = 0;
//         }
//     }

// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(NULL); cout.tie(NULL);

//     cin >> N >> M;
    
//     for (int i = 0; i < N; i++) {
//         string temp;
//         cin >> temp;
//         for (int j = 0; j < M; j++) map[i][j] = temp[j] - '0';
//     }

//     dfs(0, 0, 1, false);

//     sort(res.begin(), res.end());
//     if (res.size()) cout << res[0];
//     else cout << -1;

// }


// 논리는 맞지만 시간 초과. 최단 거리를 찾고 싶을 때는 bfs





#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
using namespace std;

int N, M;
int map[1001][1001];
int visited[1001][1001][2] = {0,};
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};

int bfs(int x, int y) {
    queue<tuple<int, int, int>> q; // a, b, 벽 부숨 bool
    q.push({x, y, 0});
    visited[x][y][0] = 1;

    while (!q.empty()) {
        int a = get<0>(q.front());
        int b = get<1>(q.front());
        int wall = get<2>(q.front());
        q.pop();

        if (a == N - 1 && b == M - 1) {
            return visited[a][b][wall];
        }

        for (int i = 0; i < 4; i++) {
            int nexta = a + dy[i];
            int nextb = b + dx[i];

            if (nexta < 0 || nexta >= N || nextb < 0 || nextb >= M) continue;
            if (visited[nexta][nextb][wall]) continue;

            if (map[nexta][nextb] && !wall) {
                visited[nexta][nextb][1] = visited[a][b][0] + 1;
                q.push({nexta, nextb, 1});
            }
            else if (!map[nexta][nextb]) {
                visited[nexta][nextb][wall] = visited[a][b][wall] + 1;
                q.push({nexta, nextb, wall});
            }

        }

    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        string temp;
        cin >> temp;
        for (int j = 0; j < M; j++) map[i][j] = temp[j] - '0';
    }

    cout << bfs(0, 0);


}

