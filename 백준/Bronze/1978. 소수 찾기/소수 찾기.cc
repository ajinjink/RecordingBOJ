#include <iostream>
using namespace std;

bool checkprime(int N) {
    if (N == 1) {
        return false;
    }
    for (int i = 2; i * i <= N; i++) {
        if (N % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int T, count = 0;
    int num[100] = {0};

    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> num[i];
    }
    for (int i = 0; i < T; i++) {
        if (checkprime(num[i])) {
            ++count;
        }
    }
    cout << count;
}