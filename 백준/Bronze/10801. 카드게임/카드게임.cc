#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arrA[10];
    int arrB[10];
    int cntA = 0, cntB = 0;
    for (int i = 0; i < 10; i++) {
        cin >> arrA[i];
    }
    for (int i = 0; i < 10; i++) {
        cin >> arrB[i];
    }
    for (int i = 0; i < 10; i++) {
        if (arrA[i] > arrB[i]) {
            cntA++;
        }
        if (arrA[i] < arrB[i]) {
            cntB++;
        }
    }
    if (cntA > cntB) {
        cout << "A";
    }
    else if (cntA < cntB) {
        cout << "B";
    }
    else {
        cout << "D";
    }

}