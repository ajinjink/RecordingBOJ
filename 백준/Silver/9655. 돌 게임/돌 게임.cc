#include <iostream>
using namespace std;

int arr[1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    if (N % 2 == 1) cout << "SK";
    else cout << "CY";
}