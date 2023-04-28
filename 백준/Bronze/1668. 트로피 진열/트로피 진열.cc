#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int arr[50];

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int leftcnt = 1, rightcnt = 1;
    bool left = true, right = true;
    int min = arr[0], max = arr[N -1];

    for (int i = 0; i < N; i++) {
        if (arr[i] > min && left) {
            min = arr[i];
            leftcnt++;
        }
        
        if (arr[N-1 -i] > max && right) {
            max = arr[N - 1 - i];
            rightcnt++;
        }
        
    }

    cout << leftcnt << '\n' << rightcnt;
}