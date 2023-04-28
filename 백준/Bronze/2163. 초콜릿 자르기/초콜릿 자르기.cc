#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, res = 0;
    cin >> N >> M;

    res += N - 1;
    res += (M - 1) * N;

    cout << res;

    
}

