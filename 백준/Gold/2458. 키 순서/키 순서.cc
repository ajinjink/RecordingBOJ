#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    bool d[501][501] = {0,};

    while (M--) {
        int a, b;
        cin >> a >> b;
        d[a][b] = true; // a가 b보다 작다
    }

    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) { // i < k && k < j 이면 i < j
                if (d[i][k] && d[k][j]) d[i][j] = true;
            }
        }
    }

    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        int temp = 0;
        for (int j = 1; j <= N; j++) { // 자기보다 작거나 큰 사람 수 세기
            if (d[i][j] || d[j][i]) temp++;
        }
        if (temp == N - 1) cnt++;
    }

    cout << cnt;
    
}