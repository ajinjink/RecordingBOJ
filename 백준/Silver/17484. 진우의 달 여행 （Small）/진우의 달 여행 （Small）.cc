#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <limits.h>
#define endl '\n'
#define tiii tuple<int, int, int>
using ll = long long;
using namespace std;

tiii arr[6][6];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        int num;
        for (int j = 0; j < M; j++) {
            cin >> num;
            arr[i][j] = {num, num, num};
        }
    }

    for (int i  = 1; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int c1, c2, c3;
            if (j == M - 1) c1 = 1e9;
            else c1 = min(get<1>(arr[i - 1][j + 1]), get<2>(arr[i - 1][j + 1]));
            c2 = min(get<0>(arr[i - 1][j]), get<2>(arr[i - 1][j]));
            if (j == 0) c3 = 1e9;
            else c3 = min(get<0>(arr[i - 1][j - 1]), get<1>(arr[i - 1][j - 1]));

            get<0>(arr[i][j]) += c1;
            get<1>(arr[i][j]) += c2;
            get<2>(arr[i][j]) += c3;
        }
    }

    int res = INT_MAX;
    for (int i = 0; i < M; i++) {
        if (res > get<0>(arr[N - 1][i])) res = get<0>(arr[N - 1][i]);
        if (res > get<1>(arr[N - 1][i])) res = get<1>(arr[N - 1][i]);
        if (res > get<2>(arr[N - 1][i])) res = get<2>(arr[N - 1][i]);
    }

    cout << res;
}
