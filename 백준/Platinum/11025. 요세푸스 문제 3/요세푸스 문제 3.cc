#include <iostream>
using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N, K;
    cin >> N >> K;

    int res = 0;
    for (int i = 1; i <= N; i++) {
        res = (res + K) % i;
    }
    cout << res + 1;
}
