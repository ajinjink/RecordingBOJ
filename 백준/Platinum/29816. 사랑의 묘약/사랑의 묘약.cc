#include <iostream>
#define mod 1000000007
using namespace std;
using ll = long long;

ll power(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b % 2) {
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        b /= 2;
    }
    return res;
}

ll inverse(ll n) {
    return power(n, mod - 2);
}

ll mul1(ll n, ll a) {
    ll res = power(2, n);
    res = (res + ((a - 1) * power(2, n / a)) % mod) % mod;
    res = (res * inverse(a)) % mod;
    return res;
}

ll mul2(ll n, ll a, ll b) {
    ll res = power(2, n);
    res = (res + ((a - 1) * power(2, n / a)) % mod) % mod;
    res = (res + ((b - 1) * power(2, n / b)) % mod) % mod;
    res = (res + ((a * b - a - b + 1) * power(2, n / (a * b))) % mod) % mod;
    res = (res * inverse(a * b)) % mod;
    return res;
}

int main() {
    ll K;
    cin >> K;
    ll N = K * 2023;

    ll res = power(2, N);
    res = (res - mul1(N, 7) + mod) % mod;
    res = (res - mul1(N, 17) + mod) % mod;
    res = (res + mul2(N, 7, 17)) % mod;

    cout << res << endl;
}