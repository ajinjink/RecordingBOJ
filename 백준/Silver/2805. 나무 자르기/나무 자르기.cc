#include <iostream>
#include <algorithm>
using namespace std;

long long N, M;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;

    long long* arr = new long long[N];
    for (long long i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + N);

    long long l = 0, r = arr[N - 1];
    long long res = 0;

    while (l <= r) {
        long long mid = (l + r) / 2;
        long long sum = 0;

        for (long long i = 0; i < N; i++) {
            if (arr[i] >= mid) {
                sum += (arr[i] - mid);
            }
            else {
                continue;
            }
        }
        if (sum >= M) {
            res = max(res, mid);
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    cout << res;
}