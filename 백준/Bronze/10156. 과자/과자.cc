#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int K, N, M;
    cin >> K >> N >> M;

    if (M > K * N) {
        cout << 0;
    }
    else {
        cout << K * N - M;
    }
}







