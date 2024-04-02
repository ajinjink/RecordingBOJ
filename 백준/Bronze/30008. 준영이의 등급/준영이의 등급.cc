#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
#define pii pair<int, int>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K, P;
    cin >> N >> K;

    while (K--) {
        int D;
        cin >> D;

        P = D * 100 / N;
        if (P <= 4) cout << 1 << ' ';
        else if (P <= 11) cout << 2 << ' ';
        else if (P <= 23) cout << 3 << ' ';
        else if (P <= 40) cout << 4 << ' ';
        else if (P <= 60) cout << 5 << ' ';
        else if (P <= 77) cout << 6 << ' ';
        else if (P <= 89) cout << 7 << ' ';
        else if (P <= 96) cout << 8 << ' ';
        else cout << 9 << ' ';
    }

}