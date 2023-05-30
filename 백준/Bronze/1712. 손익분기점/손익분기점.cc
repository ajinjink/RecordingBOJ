#include <iostream>
#include <cstring>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int A, B, C;
    cin >> A >> B >> C;

    if (B >= C) {
        cout << -1;
        return 0;
    }
    
    int net = C - B;

    cout << A / net + 1;
    
}