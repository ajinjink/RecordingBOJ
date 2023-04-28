#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long N, M, res;
    cin >> N >> M;

    if (N > M) {
        res = N - M;
    }
    else {
        res = M - N;
    }

    cout << res;
}
