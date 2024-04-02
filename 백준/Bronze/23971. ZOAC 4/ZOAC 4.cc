#include <iostream>
#include <cmath>
#define endl '\n'
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    double h, w, n, m;
    cin >> h >> w >> n >> m;

    h = ceil(h / (n + 1));
    w = ceil(w / (m + 1));
    ll res = h * w;
    cout << res;
}