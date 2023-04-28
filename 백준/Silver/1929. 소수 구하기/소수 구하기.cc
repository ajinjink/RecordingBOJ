#include <iostream>
using namespace std;

void prime(int a, int b){
    int arr[b + 1];

    for (int i = 0; i < b + 1; i++) {
        arr[i] = i;
    }

    for (int i = 2; i < b + 1; i++) {
        if (arr[i] == 0) {
            continue;
        }
        if (a <= i) {
            cout << i << '\n';
        }
        for (int j = i * 2; j < b + 1; j+= i) {
            arr[j] = 0;
        }
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M, N;
    cin >> M >> N;

    prime(M, N);
}