#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    long sum[1000001] = {0};

    for (int i = 1; i <= N; i++) {
        long num;
        cin >> num;
        sum[i] = sum[i - 1] + num;
    }

    long count = 0;
    long remain[1000] = {0};
    for (int i = 1; i <= N; i++) {
        int rem = sum[i] % M;
        if (rem == 0) {
            count++;
        }
        
        remain[rem]++;
    }

    for (int i = 0; i < M; i++) {
        
        if (remain[i] > 1) {
            long C = 0;
            C = (remain[i] * (remain[i] - 1)) / 2;
            count += C;
        }
    }

    cout << count;
}
