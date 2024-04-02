#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#define endl '\n'
#define pii pair<int, int>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, X;
    cin >> N >> X;

    vector<int> v(N);
    for (int i = 0; i < N; i++) cin >> v[i];

    ll sum = 0, cnt = 1;
    for (int i = 0; i < X; i++) sum += v[i];

    ll res = sum;
    ll l = 0, r = X - 1;
    while (r < N - 1) {
        sum -= v[l];
        l++;
        r++;
        sum += v[r];

        if (sum > res) {
            res = sum;
            cnt = 1;
        }
        else if (sum == res) cnt++;
    }

    if (res == 0) cout << "SAD";
    else cout << res << endl << cnt;
}
