
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, count = 0;
    cin >> N;
    long arr[2001];

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + N);

    for (int ind = 0; ind < N; ind++) {
        int begin = 0;
        int end = N - 1;
        while (begin < end) {
            long sum = arr[begin] + arr[end];
            if (sum == arr[ind]) {
                if (begin != ind && end != ind) {
                    count++;
                    break;
                }
                else if (begin == ind) {
                    begin++;
                }
                else if (end == ind) {
                    end--;
                }
                
            }
            else if (sum < arr[ind]) {
                begin++;
            }
            else if (sum > arr[ind]) {
                end--;
            }

        }
    }
    cout << count;
}
