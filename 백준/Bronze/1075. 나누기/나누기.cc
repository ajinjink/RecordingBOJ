#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long N, num;
    int F;
    cin >> N >> F;

    num = (N / 100) * 100;

    for (int i = 0; i < F; i++) {
        if ((num + i) % F == 0) {
            cout.width(2);
            cout.fill('0');
            cout << i;
        }
    }



}