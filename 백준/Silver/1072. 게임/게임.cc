#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long X, Y, Z;

    cin >> X >> Y;
    Z = (Y * 100) / X;


    if (Z >= 99) {
        cout << -1;
        return 0;
    }

    long l = 0, r = 1e9, res = 0;

    while (l <= r) {
        long mid = (l + r) / 2;
        long tempZ = ((Y + mid)*100) / (X + mid);
        if (tempZ > Z) {
            r = mid - 1;
            res = mid;
        }
        else {
            l = mid + 1;
        }
    }
    cout << res;
}