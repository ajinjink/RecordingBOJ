#include <iostream>
#include <cmath>
using namespace std;
#define MAX 10000001


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long A, B; // 거의 소수 범위
    cin >> A >> B;

    long arr[MAX]; // 10^14의 제곱근인 10^7까지 탐색
    for (int i = 2; i < MAX; i++) {
        arr[i] = i;
    }

    for (int i = 2; i <= sqrt(MAX); i++) { // 에라토스테네스의 체
        if (!arr[i]) {
            continue;
        }
        for (int j = 2 * i; j < MAX; j += i) {
            arr[j] = 0;
        }
    } // 0이 아니면 소수

    int count = 0; // 거의 소수 개수
    for (int i = 2; i < MAX; i++) {
        if (!arr[i]) { // 소수가 아니면 넘어가
            continue;
        }
        else { // 소수이면
            long temp = arr[i];
            while ((double)arr[i] <= (double)B / (double)temp) { // temp <= B
                if ((double)arr[i] >= (double)A / (double)temp) { // temp >= A
                    count++;
                }
                temp *= arr[i];
            }
        }
    }

    cout << count;

    
    
}