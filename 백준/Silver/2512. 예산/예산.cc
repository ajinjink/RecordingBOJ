#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    unsigned int N, M;
    cin >> N;
    
    unsigned int sumtemp = 0;
    unsigned int arr[10000];
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        sumtemp += arr[i];
    }

    cin >> M;

    sort(arr, arr + N);
    if (M >= sumtemp) {
        cout << arr[N - 1];
        return 0;
    }

    unsigned int l = 0, r = M;
    unsigned int res = 0;

    while (l <= r) {
        unsigned int mid = (l + r) / 2;
        unsigned int sum = 0;

        for(int i = 0; i < N; i++) {
            if (arr[i] >= mid) {
                sum += mid;
            }
            else {
                sum += arr[i];
            }
        }

        if (sum <= M) {
            l = mid + 1;
            res = mid;
        }
        else {
            r = mid - 1;
        }
    }
    cout << res;

}