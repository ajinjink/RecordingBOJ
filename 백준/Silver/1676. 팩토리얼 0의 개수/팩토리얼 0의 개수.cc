
#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int count = 0;
    for (int i = 0; i < N; i++) {
        int temp = i + 1;
        while (temp % 5 == 0) {
            count++;
            temp /= 5;
        }
    }

    cout << count;
}