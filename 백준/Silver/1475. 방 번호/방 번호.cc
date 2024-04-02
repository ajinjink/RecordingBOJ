#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
#define pii pair<int, int>
using ll = long long;
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string num;
    cin >> num;

    int arr[10] = {0};
    for (char c : num) {
        arr[c - '0']++;
    }

    arr[6] += arr[9];
    arr[9] = 0;
    if (arr[6] % 2) arr[6] = arr[6] / 2 + 1;
    else arr[6] /= 2;

    int res = 0;
    for (int i = 0; i < 10; i++) res = max(res, arr[i]);

    cout << res;
    
    
}