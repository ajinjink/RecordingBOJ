/*
n = 11, 11번 합성한 함수는
f_8(f_2(f_1(x)))와 같다.
11(10) = 1011(2)

*/

#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
#define pii pair<int, int>
using ll = long long;
using namespace std;

int m, q, n, x;
int f[200001][19] = {0,}; // 가로 x, 세로 중첩된 합성함수 개수 f(f(f(x)))
// f[i][j] = f를 2^j 번 합성한 결과

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> f[i][0]; // 원래 f(i) 값. f를 2^0번 합성한 값
    }

    // f_8(x) = f_4(f_4(x))
    for (int j = 1; j < 19; j++) { // 19 bits
        for (int i = 1; i <= m; i++) {
            f[i][j] = f[f[i][j - 1]][j - 1];
            // 2^{j-1} 합성한 f를 또 2^{j-1} 합성 -> 2^j 합성
        } 
    }

    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> n >> x;
        for (int bit = 18; bit >= 0; bit--) {
            if ((n & (1 << bit))) x = f[x][bit];
            // n=11 -> n=1011 -> f_8(f_2(f_1(x)))
        }
        cout << x << endl;
    }
}