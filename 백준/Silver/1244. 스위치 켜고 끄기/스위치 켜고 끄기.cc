#include <bits/stdc++.h>
#define endl '\n'
#define pii pair<int, int>
using ll = long long;
using namespace std;

int arr[101];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N;

    for (int i = 1; i <= N; i++) cin >> arr[i];

    cin >> M;
    for (int i = 0; i < M; i++) {
        int gender, num;
        cin >> gender >> num;

        if (gender == 1) {
            for (int j = num; j <= N; j += num) arr[j] = !arr[j];
        }
        else if (gender == 2) {
            if (num == 1 || num == N || arr[num - 1] != arr[num + 1]) arr[num] = !arr[num];
            else {
                for (int j = 1; j <= min(num - 1, N - num); j++) {
                    if (arr[num + j] != arr[num - j]) {
                        for (int k = num - j + 1; k <= num + j - 1; k++) arr[k] = !arr[k];
                        break;
                    }
                    else if (num - j == 1 || num + j == N) {
                        for (int k = num - j; k <= num + j; k++) arr[k] = !arr[k];
                        break;
                    }
                }
            } 
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << arr[i] << ' ';
        if (i % 20 == 0) cout << endl;
    }

}