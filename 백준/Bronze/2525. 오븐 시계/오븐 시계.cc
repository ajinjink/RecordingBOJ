#include <iostream>
#include <cstring>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int A, B, C;
    cin >> A >> B >> C;
    int h, m;
    h = C / 60;
    m = C - h * 60;

    
    if (B + m >= 60) {
        A += 1;
    }
    B = (B + m) % 60;
    A = (A + h) % 24;

    cout << A << ' ' << B;
    
}
