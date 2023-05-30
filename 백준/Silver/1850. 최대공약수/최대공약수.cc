#include <iostream>
#include <algorithm>
using namespace std;

long long GCD(long long A, long long B) {
    if (B == 0) {
        return A;
    }

    return GCD(B, A % B);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    long long A = 1, B = 1, res;
    cin >> A >> B;

    if (A > B) {
        res = GCD(A, B);
    }
    else {
        res = GCD(B, A);
    }

    for (int i = 0; i < res; i++) {
        cout << 1;
    }
}