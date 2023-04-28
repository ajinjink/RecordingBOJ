

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    unsigned long long n;
    cin >> n;

    if (n == 0) {
        cout << 0;
        return 0;
    }
    if (n == 1) {
        cout << 1;
        return 0;
    }

    unsigned long long l = 0, r = 3038000000;
    unsigned long long res;

    while(l <= r) {
        unsigned long long mid = (l + r) / 2;

        if (mid * mid >= n) {
            r = mid - 1;
            res = mid;
        }
        else {
            l = mid + 1;
        }
    }
    cout << res;

}