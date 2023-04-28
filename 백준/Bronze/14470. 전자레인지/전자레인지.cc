#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int A, B, C, D, E;
    long res = 0;
    cin >> A >> B >> C >> D >> E;

    if (A < 0) {
        res += ((-1) * A * C);
        res += D;
        res += (B * E);
    }
    else {
        res += ((B - A) * E);
    }

    cout << res;
}