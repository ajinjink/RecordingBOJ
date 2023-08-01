#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

bool checkprime(long long p) {
    for (long long i = 2; i <= sqrt(p); i++) {
        if (p % i == 0) return false;
    } 

    return true;

}

long long _pow(long long a, long long p, long long MOD) {
	if (p == 0) return 1;
    if (p == 1) return a;
    if (p % 2 == 0) return ((_pow(a, p/2, MOD) % MOD) * (_pow(a, p/2, MOD) % MOD)) % MOD;
    else return a * (_pow(a, p - 1, MOD) % MOD) % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (1) {
        long long p, a;
        cin >> p >> a;

        if (p == 0 && a == 0) break;

        if (p < a) swap(a, p);

        if (checkprime(p)) cout << "no\n";
        else {
            if (_pow(a, p, p) == a) cout << "yes\n";
            else cout << "no\n";
        }
    }
    
    return 0;
}