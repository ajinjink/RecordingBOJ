#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, temp;
    cin >> n;

    int arr[500];
    int ans_arr[500];

    cin >> arr[0]; 
    

    for (int i = 1; i < n; i++) { 
        cin >> temp; 
        ans_arr[0] = arr[0] + temp;
        for (int j = 1; j <= i - 1; j++) {
            cin >> temp;
            ans_arr[j] = max(arr[j-1] + temp, arr[j] + temp);
        }
        cin >> temp; 
        ans_arr[i] = arr[i - 1] + temp;

        for (int j = 0; j < i + 1; j++) {
            arr[j] = ans_arr[j];
        }
    }

    sort(ans_arr, ans_arr + n);
    if (n == 1) {
        ans_arr[0] = arr[0];
    }
    cout << ans_arr[n - 1];

}