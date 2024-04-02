#include <bits/stdc++.h>
#define endl '\n'
#define pii pair<int, int>
using ll = long long;
using namespace std;

int arr[51];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, score, P;
    cin >> N >> score >> P; // N개의 점수, 새로운 점수, 랭킹에 들어가는 개수

    for (int i = 0; i < N; i++) cin >> arr[i];

    if (N >= P && arr[P - 1] >= score) {
        cout << -1;
        return 0;
    }

    int l = 0, r = N - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (arr[mid] > score) l = mid + 1;
        else r = mid - 1;
    }

    // cout << l << ' ' << r;
    cout << l + 1;
}