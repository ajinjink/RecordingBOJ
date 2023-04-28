#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string num;
    cin >> num;

    int* arr = new int[num.length() + 1];
    for (int i = 0; i < num.length(); i++) {
        arr[i] = num[i] - '0';
    }

    sort(arr, arr + num.length());

    for (int i = num.length() - 1; i >= 0; i--) {
        cout << arr[i];
    }
    
}


