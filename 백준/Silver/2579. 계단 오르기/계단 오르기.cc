#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int arr[300];
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int sum[300] = {0};
    sum[0] = arr[0];
    sum[1] = arr[0] + arr[1];
    sum[2] = max(arr[0] + arr[2], arr[1] + arr[2]);

    int st = 3;
    while (st < N) {
        sum[st] = max(sum[st - 2] + arr[st], sum[st - 3] + arr[st - 1] + arr[st]);
        st++;
    }

    cout << sum[N - 1];

    
}
