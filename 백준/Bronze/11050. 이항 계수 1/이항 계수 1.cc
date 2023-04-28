#include <iostream>
using namespace std;

int main() {
    int N, K, temp = 1, temp2 = 1;
    cin >> N >> K;

    for (int i = K + 1; i <= N; i++) {
        temp *= i;
    }
    for (int i = 1; i <= N - K; i++) {
        temp2 *= i;
    }
    cout << temp / temp2;
    
}