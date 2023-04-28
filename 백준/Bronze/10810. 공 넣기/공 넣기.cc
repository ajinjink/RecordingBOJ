#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    int* arr = new int[N + 1];
    for (int i = 0; i <= N; i++) {
        arr[i] = 0;
    }

    int begin, end, num;
    for (int i = 0; i < M; i++) {
        cin >> begin >> end >> num;
        for (int j = begin; j <= end; j++) {
            arr[j] = num;
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << arr[i] << ' ';
    }
}

