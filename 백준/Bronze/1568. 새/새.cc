#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int arr[50001] = {0};

    for (int i = 1; i <= 50000; i++) {
        arr[i] = arr[i - 1] + i;
        if (arr[i] > N) {
            break;
        }
    }
    // for (int i = 1; i <= N; i++) {
    //     cout << arr[i] << ' ';
    // }
    // cout << arr[1] << '\n';

    

    int res = 0;

    while (N > 0) {
        for (int i = 0; i <= N; i++) {
            if (arr[i + 1] > N) {
                res += i;
                N -= arr[i];
                break;
            }
        }
        // cout << res << '\n';
    }

    cout << res;
}