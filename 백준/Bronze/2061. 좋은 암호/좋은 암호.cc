#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string K;
    int L;
    cin >> K >> L;

    for (int i = 2; i < L; i++) {
        int res = 0, temp = 1;
        for (int j  = K.length() - 1; j >= 0; j--) {
            res = (res + (K[j] - '0') * temp) % i;
            temp *= 10;
            temp %= i;
        }
        if (res == 0) {
            cout << "BAD " << i;
            return 0;
        }
    }
    cout << "GOOD";

    
}