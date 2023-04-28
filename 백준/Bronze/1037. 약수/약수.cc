#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num;
    int arr[51];

    cin >> num;
    for (int i = 0; i < num; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + num);

    long long res = arr[num - 1];

    
    if (num == 1) {
        res = arr[0] * arr[0];
    }
    else {
        res = arr[0] * arr[num - 1];
    }

    cout << res;


}
