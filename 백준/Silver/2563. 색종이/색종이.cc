#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
#define pii pair<int, int>
using ll = long long;
using namespace std;

int map[101][101] = {0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;

        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 10; k++) {
                map[a + j][b + k] = 1;
            }
        }
    }

    int res = 0;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            res += map[i][j];
        }
    }

    cout << res;
}