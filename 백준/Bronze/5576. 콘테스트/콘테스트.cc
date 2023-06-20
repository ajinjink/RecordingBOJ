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

    int arr1[10];
    int arr2[10];

    for (int i = 0; i < 10; i++) {
        cin >> arr1[i];
    }
    for (int i = 0; i < 10; i++) {
        cin >> arr2[i];
    }
    sort(arr1, arr1 + 10);
    sort(arr2, arr2 + 10);

    cout << arr1[7] + arr1[8] + arr1[9] << ' ' << arr2[7] + arr2[8] + arr2[9];
    
}
