#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<long> divisor;

void getDivisor(long long n) {
    for (long i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            divisor.push_back(i);
            divisor.push_back(n / i);
        }
    }
    divisor.push_back(n);
}

long long phi(long long n) {
    long long res = n;

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

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long n;
    cin >> n;
    
    if (n == 1) {
        cout << 1;
        return 0;
    }

    getDivisor(n);

    for (long long i = 0; i < divisor.size(); i++) {
        
        if (divisor[i] * phi(divisor[i]) == n) {
            cout << divisor[i];
            return 0;
        }
        
    }

    cout << -1;
}

