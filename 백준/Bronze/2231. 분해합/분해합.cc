#include <iostream>
using namespace std;

int main() {
    int N, sum, temp;
    cin >> N;

    for (int i = 0; i < N; i++) {
        temp = i;
        sum = i;
        while(temp > 0){
            sum += temp % 10;
            temp /= 10;
        }
        if (sum == N) {
            cout << i;
            break;
        }
        if (i == N-1) {
            cout << 0;
        }
    }

}