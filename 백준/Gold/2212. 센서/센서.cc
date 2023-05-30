#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    int arr[10001] = {0};  
    int dist[10000] = {0};

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + N);

    for (int i = 1; i < N; i++) {
        dist[i - 1] = arr[i] - arr[i - 1];
    }
    sort(dist, dist + N - 1);

    long long sum = 0;
    for (int i = 0; i < N - K; i++) {
        sum += dist[i];
    }

    cout << sum;
    

}