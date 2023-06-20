#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arr[6], sum = 0;
    for (int i = 0; i < 6; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    sort(arr, arr + 4);

    cout << sum - arr[0] - min(arr[4], arr[5]);
    



}