#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, K, count = 0;
    cin >> N >> K;

    int arr[10];

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    while (K != 0) {
        for (int i = N - 1; i >= 0; i--) {
            if (K >= arr[i]) {
                count += (K / arr[i]);
                K = K % arr[i];
            }
        }
    }

    cout << count;

}