#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    unsigned long long N, M;
    cin >> N >> M;

    unsigned long long* arr = new unsigned long long[N];
    for (int i = 0; i < N; i++) {
        cin >> arr[i];        
    }
    sort(arr, arr + N);

    unsigned long long l = 0, r = arr[0] * M, res = 0;

    while (l <= r) {
        unsigned long long mid = (l + r) / 2;
        unsigned long long count = 0;

        for (int i = 0; i < N; i++) {
            count += mid / arr[i]; 
            if (count > M) {
                break;
            }
        }

        if (count >= M) {
            if (res == 0) {
                res = mid;
            }
            else {
                res = min(mid, res);

            }
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }

    cout << res;

    delete[] arr;
}