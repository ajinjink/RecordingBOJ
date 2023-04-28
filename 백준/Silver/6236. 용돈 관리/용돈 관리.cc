#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    int* arr = new int[N];
    int sum = 0, max = 0;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        sum += arr[i];
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    int l = max, r = sum, res = 0;

    while (l <= r) {
        int mid = (l + r) / 2; // 한 번에 인출하는 돈
        int count = 1, temp = mid; // temp가 지금 남은 돈

        for (int i = 0; i < N; i++) {
            if (temp - arr[i] >= 0) {
                temp -= arr[i];
            }
            else {
                count++;
                temp = mid;
                temp -= arr[i];
                if (temp < 0) {
                    continue;
                }
            }
            // cout << "mid:" << mid << ",temp:" << temp << ", count:" << count << endl;
        }
        // cout << "l:" << l << ", r:" << r << ", mid:" << mid << ", count:" << count << endl;


        if (count > M) {
            l = mid + 1;
        }
        else {
            res = mid;
            r = mid - 1;
        }
        // cout << res << endl;

    }

    cout << res;
}