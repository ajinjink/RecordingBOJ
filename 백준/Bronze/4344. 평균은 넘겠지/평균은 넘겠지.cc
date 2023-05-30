#include <iostream>
#include <cstring>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int C;
    cin >> C;

    int N, arr[1000];

    for (int i = 0; i < C; i++) {
        cin >> N;
        double sum = 0;
        for (int j = 0; j < N; j++) {
            cin >> arr[j];
            sum += arr[j];
        }
        double avg = sum / (double)N;
        int count = 0;
        for (int j = 0; j < N; j++) {
            if (arr[j] > avg) {
                count++;
            }
        }
        cout << fixed;
        cout.precision(3);
        cout << (double)count/(double)N * 100 << "%" << '\n';
        memset(arr, 0, N);
    }
}