#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>
#define endl '\n'
#define pii pair<int, int>
using ll = long long;
using namespace std;

static long d[100001][5][5];
static int m[5][5] = {0,};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    for (int i = 0; i < 5; i++) { 
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 100001; k++) d[k][i][j] = INT_MAX; // 큰 값으로 초기화 (min 쓰려고)

            if (i == j) m[i][j] = 1; // 움직임 코스트 초기화
            else if (i == 0 || j == 0) m[i][j] = 2;
            else if (i - j == 1 || j - i == 1 || i - j == 3 || j - i == 3) m[i][j] = 3;
            else if (i - j == 2 || j - i == 2) m[i][j] = 4;
        }
    }
    m[0][0] = 0;
    d[0][0][0] = 0;

    int n, k = 1;

    while (1) {
        cin >> n;
        if (n == 0) break;

        for (int i = 0; i < 5; i++) {
            if (n == i) continue; // 같은 발 안 됨

            for (int j = 0; j < 5; j++) // 오른발 옮겨
                d[k][i][n] = min(d[k - 1][i][j] + m[j][n], d[k][i][n]);
        }

        for (int j = 0; j < 5; j++) {
            if (n == j) continue; // 같은 발 안 됨

            for (int i = 0; i < 5; i++) // 왼발 옮겨
                d[k][n][j] = min(d[k - 1][i][j] + m[i][n], d[k][n][j]);
        }

        k++;
    }

    k--;
    long res = INT_MAX;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            res = min(res, d[k][i][j]);
        }
    }

    cout << res;
    
}