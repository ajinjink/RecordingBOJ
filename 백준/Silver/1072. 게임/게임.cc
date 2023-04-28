#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long double X, Y;
    long Z;

    cin >> X >> Y;
    Z = (Y / X) * 100;

    if (Z >= 99) {
        cout << -1;
        return 0;
    }

    long l = 0, r = X, res = 0;

    while (l <= r) {
        long mid = (l + r) / 2;
        long tempZ = ((Y + mid) / (X + mid)) * 100;
        if (tempZ == Z) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
            res = mid;
        }
    }
    cout << res;
}