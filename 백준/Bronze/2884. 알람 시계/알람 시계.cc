#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int H, M;
    cin >> H >> M;

    if (M >= 45) {
        M -= 45;
        cout << H << ' ' << M;
    }
    else {
        M = M + 15;
        if (H == 0) {
            H = 23;
        }
        else {
            H -= 1;
        }
        cout << H << ' ' << M;
    }
}