#include <iostream>
#include <cmath>
using namespace std;
#define MAX 10001


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M, N;
    cin >> M >> N;

    int arr[MAX]; 
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

    int min = 100000;
    long sum = 0;
    bool flag = false;
    for (int i = M; i <= N; i++) {
        if (!arr[i]) { // 소수가 아니면 넘어가
            continue;
        }
        else { // 소수이면
            flag = true;
            if (min > arr[i]) {
                min = arr[i];
            }
            sum += arr[i];
        }
    }
    if (flag) {
        cout << sum << '\n' << min;
    }
    else {
        cout << -1;
    }

    
    
}






