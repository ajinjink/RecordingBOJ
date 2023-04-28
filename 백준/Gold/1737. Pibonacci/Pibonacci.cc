#include <iostream>
#include <cmath>
using namespace std;
#define MAX 1000000000000000000

unsigned long long dp[1001][1001];
long double n;

unsigned long long Pibonacci(int i , int j) {
    long double idx = n - 1 * i - M_PI * (long double)j;
    
    if (idx < 0) {
        return 0;
    }
    if (0 <= idx && idx <= M_PI) {
        return 1;
    }

    if (dp[i][j] != 0) {
        return dp[i][j];
    }
    return dp[i][j] = (Pibonacci(i + 1, j) + Pibonacci(i, j + 1)) % MAX;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;


    cout << Pibonacci(0, 0) % MAX;


}
