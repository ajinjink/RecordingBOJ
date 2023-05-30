#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arr[6] = {1, 1, 2, 2, 2, 8};
    int temp;

    for (int i = 0; i < 6; i++) {
        cin >> temp;
        cout << arr[i] - temp << ' ';
    }
}