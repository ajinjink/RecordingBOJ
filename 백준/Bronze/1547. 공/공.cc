#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arr[3] = {1, 0, 0};
    int M;
    cin >> M;
    int c1, c2;
    for (int i = 0; i < M; i++) {
        cin >> c1 >> c2;
        swap(arr[c1 - 1], arr[c2 - 1]);
    }
    
    for (int i = 0; i < 3; i++) {
        if (arr[i] == 1) {
            cout << i + 1;
            return 0;
        }
    }
}