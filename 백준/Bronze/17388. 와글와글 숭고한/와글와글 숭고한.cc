#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arr[3];
    int sum = 0, min = 101, minindex = 3;
    for (int i = 0; i < 3; i++) {
        cin >> arr[i];
        sum += arr[i];
        if (arr[i] < min) {
            min = arr[i];
            minindex = i;
        }
    }

    if (sum >= 100) {
        cout << "OK";
        return 0;
    }
    else {
        if (minindex == 0) {
            cout << "Soongsil";
            return 0;
        }
        if (minindex == 1) {
            cout << "Korea";
            return 0;
        }
        if (minindex == 2) {
            cout << "Hanyang";
            return 0;
        }
    }
}