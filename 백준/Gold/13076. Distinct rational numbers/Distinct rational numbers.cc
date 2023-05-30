#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, temp;
    cin >> T;

    long long arr[10001] = {0};

    for (int t = 1; t <= T; t++) {

        int N;
        cin >> N;
        long long total = 0;

        int index = 1;
        for (int i = 2; i <= 10000; i++) {
            if (arr[i]) {
                index = i;
                total = arr[i];
            }
            if (i >= N) {
                break;
            }
        }

        // cout << "total 1 : " << total << ", index : " << index << '\n';
        

        for (int j = index + 1; j <= N; j++) {
            int n = j;
            int res = n;

            for (long i = 2; i <= sqrt(n); i++) {
                if (n % i == 0) { // i가 n의 소인수인가
                    res = res - res / i;
                    while (n % i == 0) {
                        n /= i;
                    }
                }
            }
            if (n > 1) { // 아직 소인수가 남아있으면
                res = res - res / n; // 제곱근가지만 탐색해서 소인수 하나 남아있는 거
            }

            total += res;

        }

        arr[N] = total;

        cout << total + 2 << '\n';

    }


}
