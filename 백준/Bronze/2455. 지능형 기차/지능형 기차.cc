#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int current = 0;
    int out, in;
    int arr[4];

    for (int i = 0; i < 4; i++) {
        cin >> out >> in;
        current -= out;
        current += in;
        arr[i] = current;
    }

    sort(arr, arr + 4);
    cout << arr[3];
    
}

