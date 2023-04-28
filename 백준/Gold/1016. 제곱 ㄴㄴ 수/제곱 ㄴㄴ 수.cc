#include <iostream>
using namespace std;


long long num[1000000] = {0};

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
    long long min, max;
    cin >> min >> max;

    num[1] = 1;

    for (int i = 1; i <= 1000000; i++) {
        for (int j = 2 * i; j <= 1000000; j += i) {
            num[j] -= num[i];
        }
    }
    
    cout << cnt(max) - cnt(min - 1);
}
