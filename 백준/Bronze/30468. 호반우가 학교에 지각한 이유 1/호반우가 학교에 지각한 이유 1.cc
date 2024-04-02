#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
#define pii pair<int, int>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b, c, d, n;
    cin >> a >> b >> c >> d >> n;

    int sum = a + b + c + d;

    if (sum / 4 >= n) cout << 0;
    else cout << 4 * n - sum;
}