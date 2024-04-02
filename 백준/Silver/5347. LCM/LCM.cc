#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define endl '\n'
#define pii pair<int, int>S
using ll = long long;
using namespace std;

ll GCD(ll A, ll B) {
    if (B == 0) {
        return A;
    }

    return GCD(B, A % B);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll n;
    cin >> n;
    for (ll i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        cout << a * b / GCD(a, b) << endl;
    }
}
