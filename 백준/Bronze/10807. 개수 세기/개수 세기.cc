#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int arr[101];

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int target, count = 0;
    cin >> target;

    for (int i = 0; i < N; i++) {
        if (arr[i] == target) {
            count++;
        }
    }

    cout << count;

    
}