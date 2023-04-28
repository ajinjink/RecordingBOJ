#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    int *arr = new int[N];
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int l = 0, r = N - 1;
    
    int resl = l, resr = r;

    int min = arr[l] + arr[r];

    while (l < r) {
        int sum = arr[l] + arr[r];
        if (abs(sum) < abs(min)) {
            min = sum;
            resl = l;
            resr = r;
        }

        if (sum > 0) {
            r--;
        }
        if (sum < 0) {
            l++;
        }
        if (sum == 0) {
            cout << arr[l] << ' ' << arr[r];
            return 0;
        }
    }

    cout << arr[resl] << ' ' << arr[resr];
    delete[] arr;

   
}

