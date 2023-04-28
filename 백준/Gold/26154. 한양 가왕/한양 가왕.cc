#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    int tmp;

    int arr[1000][2];

    for (int i = 0; i < N; i++) {
        cin >> arr[i][0] >> arr[i][1];
    }

    if (N != 1 && M != 0) {  
        if (M <= N) {
            M = M - 1;
        }  
        if (M > N) {         
            M = (M - 1) % N + N;
        }

        for (int j = 0; j < M + 1; j++) {
            int moved = 0;
            for (int i = 0; i < N; i++) {
                if (i == 0) { 
                    if (arr[i][0] > arr[i][1])
                        swap(arr[i][0], arr[i][1]);
                    tmp = arr[0][0]; 
                    moved = 0;
                }
                else {
                    if (arr[i][0] > arr[i][1])
                        swap(arr[i][0], arr[i][1]);
                    arr[i-1][moved] = arr[i][1]; 
                    moved = 1;
                }
            }
            arr[N - 1][1] = tmp;
        }
    }
    
    for (int i = 0; i < N; i++) {
        if (arr[i][0] > arr[i][1])
            swap(arr[i][0], arr[i][1]);
        cout << arr[i][0] << ' ' << arr[i][1] << '\n';
    }
}
