#include <bits/stdc++.h>
#define endl '\n'
#define tiii tuple<int, int, int>
using ll = long long;
using namespace std;

int arr[100000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    double maxdist = 0;
    int prev = 0;
    for (int i = 0; i < M; i++) {
        cin >> arr[i];
        if (maxdist < arr[i] - prev) {
            maxdist = arr[i] - prev;
        }
        prev = arr[i];
    }
    if (maxdist < N - prev) {
        maxdist = N - prev;
    }

    if (M == 1) {
        cout << maxdist;
        return 0;
    }

    if (arr[0] > ceil(maxdist / 2)) cout << arr[0];
    else if (N - arr[M - 1] > ceil(maxdist / 2)) cout << N - arr[M - 1];
    else cout << ceil(maxdist / 2);
}
