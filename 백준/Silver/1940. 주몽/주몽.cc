#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, count = 0;
    cin >> N >> M;

    int arr[15001];

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + N);
    
    int begin = 0;
    int end = N - 1;
    

    while (begin < end) {
        int sum = arr[begin] + arr[end];

        if (sum == M) {
            count++;
            begin++;
            end--;
           
        }
        else if (sum < M) {
            begin++;
            
        }
        else if (sum > M) {
          
            end--;
        }
        
    }

    cout << count;

}