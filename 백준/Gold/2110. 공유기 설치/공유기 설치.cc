#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, C;
    cin >> N >> C;

    int* arr = new int[N];


    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + N);

    int maxdist = arr[N - 1];


    int l = 0, r = maxdist, mid, res = 0;


    while (l <= r) {
        mid = (l + r) / 2;

        int tempdist = 0, count = 1;

        for (int i = 1; i < N; i++) {
            if (tempdist + arr[i] - arr[i - 1] >= mid) {
                count++;
                tempdist = 0;
            }
            else {
                tempdist += arr[i] - arr[i - 1];
            }
        }

        if (count >= C) {
            res = max(mid, res);
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }

    cout << res;

    delete[] arr;
}

