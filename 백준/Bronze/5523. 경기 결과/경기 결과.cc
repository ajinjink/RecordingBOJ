#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, a, b;
    int cntA = 0, cntB = 0;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        if (a > b) {
            cntA++;
        }
        if (b > a) {
            cntB++;
        }
    }

    cout << cntA << ' ' << cntB;

}