#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long n;
    cin >> n;
    long long res = n;

    for (long i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) { // i가 n의 소인수인가
            res = res - res / i;
            while (n % i == 0) {
                n /= i;
            }
        }
    }
    if (n > 1) {
        res = res - res / n;
    }

    cout << res;
}
