#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int c1, n = 1;
    cin >> c1;

    while (c1 != 1) {
        if (c1 % 2 == 0) {
            c1 /= 2;
        }
        else {
            c1 = 3 * c1 + 1;
        }
        n++;
    }
    cout << n;
}