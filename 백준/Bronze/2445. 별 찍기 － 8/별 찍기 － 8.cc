#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            cout << "*";
        }
        for (int j = 0; j < 2 * n - 2 * i; j++) {
            cout << ' ';
        }
        for (int j = 0; j < i; j++) {
            cout << "*";
        }
        cout << '\n';
    }
    for (int i = n - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            cout << "*";
        }
        for (int j = 0; j < 2 * n - 2 * i; j++) {
            cout << ' ';
        }
        for (int j = 0; j < i; j++) {
            cout << "*";
        }
        cout << '\n';
    }



}