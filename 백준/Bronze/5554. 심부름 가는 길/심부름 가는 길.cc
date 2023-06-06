#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int res = 0, temp;

    for (int i = 0; i < 4; i++) {
        cin >> temp;
        res += temp;
    }

    cout << res / 60 << '\n' << res - 60*(res/60);
}
