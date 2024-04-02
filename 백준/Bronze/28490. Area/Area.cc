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

    int n;
    cin >> n;

    int res = 0;
    while (n--) {
        int a, b;
        cin >> a >> b;
        res = max(res, a * b);
    }

    cout << res;

}