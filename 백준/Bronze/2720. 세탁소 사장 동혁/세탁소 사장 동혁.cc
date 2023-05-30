#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int num;
        int q, d, n, p;

        cin >> num;
        
        q = (num / 25);
        num -= q * 25;
        d = (num / 10);
        num -= d * 10;
        n = (num / 5);
        num -= n * 5;
        p = num;

        cout << q << ' ' << d << ' ' << n << ' ' << p << '\n';

    }

}
