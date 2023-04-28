#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long N, k;
    cin >> N >> k;

    long long l = 1, r = k, res;

    while (l <= r) {
        long long mid = (l + r) / 2;
        long long count = 0;

        for (int i = 1; i <= N; i++) {
            count += min(N, mid / i);
        }

        if (count >= k) {
            r = mid - 1;
            res = mid;
        }
        else {
            l = mid + 1;
        
        }
    }

    cout << res;
}