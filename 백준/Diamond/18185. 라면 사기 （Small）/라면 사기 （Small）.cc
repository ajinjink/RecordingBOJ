#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
#define pii pair<int, int>
using ll = long long;
using namespace std;

static ll N;
static ll A[3][1000001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;

    for (int i = 0; i < N; i++) cin >> A[0][i];

    for (int i = 1; i < N; i++) {
        ll t = min(A[0][i], A[0][i - 1]);
        A[0][i] -= t;
        A[0][i - 1] -=t;
        A[1][i] += t;
        if (i == 1) continue;
        t = min(A[0][i], A[1][i - 1]);
        A[0][i] -= t;
        A[1][i - 1] -=t;
        A[2][i] += t;
    }
    ll res = 0;
    for (int i = 0; i < N; i++) res += A[0][i] * 3 + A[1][i] * 5 + A[2][i] * 7;

    cout << res;

}