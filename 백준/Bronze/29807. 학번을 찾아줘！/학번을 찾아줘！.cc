#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T;
    cin >> T;

    int arr[5] = {0};
    for (int i = 0; i < T; i++) cin >> arr[i];

    int res = 0;

    if (arr[0] > arr[2])
        res += (arr[0] - arr[2]) * 508;
    else
        res += (arr[2] - arr[0]) * 108;

    if (arr[1] > arr[3])
        res += (arr[1] - arr[3]) * 212;
    else
        res += (arr[3] - arr[1]) * 305;
    res += arr[4] * 707;

    cout << res * 4763 << '\n';
}