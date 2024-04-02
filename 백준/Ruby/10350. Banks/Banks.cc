#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long n, res = 0;
    long double total = 0;
    cin >> n;

    vector<long long> v(n);

    for (long long i = 0; i < n; i++) {
        cin >> v[i];
        total += v[i];
    }

    for (long long i = 0; i < n; i++) {
        long double sum = 0;
        for (long long j = i; j < i + n; j++) {
            sum += v[j % n]; // 구간합
            if (sum < 0) res += ceil(fabs(sum) / total); // 이 음수면 (|구간합| / 전체합)의 올림
        }
    }

    cout << res;
}