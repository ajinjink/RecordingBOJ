#include <iostream>
using namespace std;

long long num[42000] = {0};

long long cnt(long long n) {
    long long count = 0;
    if (n == 1) {
        return 1;
    }
    for (long long i = 1; i * i <= n; i++) {
        count += num[i] * n / (i * i);
    }
    return count;
}

int main() {
    long long K;
    cin >> K;

    num[1] = 1;

    for (int i = 1; i <= 42000; i++) {
        for (int j = 2 * i; j <= 42000; j += i) {
            num[j] -= num[i];
        }
    }
    
    long long l = 0, r = 2 * K, mid;

    while (l < r - 1) {
        mid = (r + l) / 2; 
        if (cnt(mid) < K) {
            l = mid;
        }
        else {
            r = mid;
        }
    }
    cout << r;
}