#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            cout << ' ';
        }
        for (int j = 0; j < 2 * N - 1 - 2 * i; j++) {
            cout << '*';
        }
        cout << '\n';
    }
    for (int i = 0; i < N - 1; i++) {
        for (int j = N - 3 - i; j >= 0; j--) {
            cout << ' ';
        }
        for (int j = 0; j < 2 * i + 3; j++) {
            cout << '*';
        }
        cout << '\n';
    }
}