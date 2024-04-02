#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
#define endl '\n'
using namespace std;

int R, C;
char map[21][21];
int alpha[30] = {0}; // 이 알파벳을 밟았는지
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};
int res = 0;

void dfs(int a, int b, int cnt) {

    res = max(res, cnt);

    for (int i = 0; i < 4; i++) {
        int nexta = a + dy[i];
        int nextb = b + dx[i];

        if (nexta < 0 || nexta >= R || nextb < 0 || nextb >= C) continue; 

        if (!alpha[map[nexta][nextb] - 'A']) {
            alpha[map[nexta][nextb] - 'A'] = 1;
            dfs(nexta, nextb, cnt + 1);
            alpha[map[nexta][nextb] - 'A'] =0;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        string temp;
        cin >> temp;
        for (int j = 0; j < C; j++) {
            map[i][j] = temp[j];
        }
    }

    alpha[map[0][0] - 'A'] = 1;
    dfs(0, 0, 1);

    cout << res;
}
