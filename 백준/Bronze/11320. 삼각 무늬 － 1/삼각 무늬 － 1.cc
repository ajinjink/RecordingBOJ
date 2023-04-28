#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int A, B;
        cin >> A >> B;
        double ratio = A / B;
        int intratio = ratio / 1;
        if (ratio == intratio) {
            cout << intratio * intratio << '\n';
        }
        else {
            cout << (intratio + 1) * (intratio + 1) << '\n';
        }

    }

}