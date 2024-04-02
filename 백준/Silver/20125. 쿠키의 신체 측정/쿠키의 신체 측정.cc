#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pii pair<int, int>
using ll = long long;

int m[1001][1001] = {0,};
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < N; j++) {
            if (line[j] == '_') m[i][j + 1] = 0;
            else m[i][j + 1] = 1;
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (m[i][j]) {
                bool heart = true;
                for (int k = 0; k < 4; k++) {
                    if (m[i + dy[k]][j + dx[k]] == 0) {
                        heart = false;
                        break;
                    }
                }

                if (heart) {
                    cout << i << ' ' << j << endl; // i = 3, j = 3
                    // 왼쪽 팔
                    int cnt = 0;
                    for (int k = j - 1; k > 0; k--) {
                        if (m[i][k]) cnt++;
                    }
                    cout << cnt << ' ';
                    // 오른쪽 팔
                    cnt = 0;
                    for (int k = j + 1; k <= N; k++) {
                        if (m[i][k]) cnt++;
                    }
                    cout << cnt << ' ';
                    // 허리
                    cnt = 0;
                    int x;
                    for (int k = i + 1; k <= N; k++) {
                        if (m[k][j]) cnt++;
                        else {
                            x = k;
                            break;
                        }
                    }
                    cout << cnt << ' ';
                    // 왼쪽 다리
                    cnt = 0;
                    for (int k = x; k <= N; k++) {
                        if (m[k][j - 1]) cnt++;
                    }
                    cout << cnt << ' ';
                    // 오른쪽 다리
                    cnt = 0;
                    for (int k = x; k <= N; k++) {
                        if (m[k][j + 1]) cnt++;
                    }
                    cout << cnt;

                    return 0;
                }
            }
        }
    }
}