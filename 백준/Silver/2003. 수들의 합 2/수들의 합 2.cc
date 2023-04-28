#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    long M;
    int arr[10001];
    int begin = 0, end = 0, count = 0;

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    long sum = arr[0];

    while (end < N) {
        if (sum == M) {
            count++;
            sum -= arr[begin];
            begin++;
            end++;
            sum += arr[end];
        }
        else if (sum > M) {
            sum -= arr[begin];
            begin++;

        }
        else {
            end++;
            sum += arr[end];
        }
    }

    cout << count;
}