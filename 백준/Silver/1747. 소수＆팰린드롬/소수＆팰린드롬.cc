#include <iostream>
#include <cmath>
using namespace std;
#define MAX 1003003

bool isPalindrome(int num) {
    string N = to_string(num);
    for (int i = 0; i < N.length() / 2; i++) {
        if (N[i] != N[N.length() - 1 - i]) {
            return false;
        }
    }
    return true;

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);



    int N;
    cin >> N;

    long arr[MAX]; 
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


    for (int i = 2; i < MAX; i++) {
        if (i >= N && arr[i] != 0) {
            if (isPalindrome(i)) {
                cout << i;
                return 0;
            }
        }
    }

    

    
    
}



