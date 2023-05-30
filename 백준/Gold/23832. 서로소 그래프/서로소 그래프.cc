#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    long long total = 0;

    for (int j = 2; j <= N; j++) {
        int n = j;
        int res = n;

        for (long i = 2; i <= sqrt(n); i++) {
            if (n % i == 0) { // i가 n의 소인수인가
                res = res - res / i;
                while (n % i == 0) {
                    n /= i;
                }
            }
        }
        if (n > 1) { // 아직 소인수가 남아있으면
            res = res - res / n; // 제곱근가지만 탐색해서 소인수 하나 남아있는 거
        }

        total += res;

    }

    cout << total;

}
