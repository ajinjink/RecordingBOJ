#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, M, temp;
    cin >> N;

    int* arr = new int[N];
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + N);

    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> temp;
        if (binary_search(arr, arr+N, temp)) {
            cout << 1 << '\n';
        }
        else {
            cout << 0 << '\n';
        }
    }
}
