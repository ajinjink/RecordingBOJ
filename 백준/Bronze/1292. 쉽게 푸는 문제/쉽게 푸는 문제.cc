#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    
    int A, B;
    cin >> A >> B;

    long long arr[1040];
    int index = 2;
    arr[1] = 1;
    for (int i = 2; i <= 45; i++) { 
        for (int j = 0; j < i; j++) {
            arr[index] = arr[index - 1] + i;
            index++;
        }
    }
    cout << arr[B] - arr[A - 1];


}