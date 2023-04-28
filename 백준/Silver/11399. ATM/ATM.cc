#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int arr[1001];
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + N);

    int sum[1001] = {0};
    int res = 0;
    for (int i = 0; i < N; i++) {
        sum[i] = sum[i - 1] + arr[i];
        res += sum[i];
    }

    cout << res;
}