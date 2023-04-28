#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M, N;
    int min, max;
    long long ressum = 0;

    cin >> M >> N;

    min = sqrt(M) / 1;
    max = sqrt(N) / 1;

    if (pow(min, 2) != M) {
        min++;
    }

    if (min > max) {
        cout << -1;
        return 0;
    }

    for (int i = min; i <= max; i++) {
        ressum += (i * i);
    }

    cout << ressum << '\n' << min * min;

}