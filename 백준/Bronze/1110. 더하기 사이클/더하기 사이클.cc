#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N; 
    cin >> N;

    if (N == 0) {
        cout << 1;
        return 0;
    }

    int ten, one, res;
    int cycle = 1;
    if (N < 10) {
        res = N * 11;
    }
    else {
        one = (N % 10 + N / 10) % 10;
        ten = N % 10;
        res = ten * 10 + one;
    }

    while (res != N) {
        cycle++;

        if (res < 10) {
            res *= 11;
        }
        else {
            one = (res % 10 + res / 10) % 10;
            ten = res % 10;
            res = ten * 10 + one;
        }
    }

    cout << cycle;
    
}