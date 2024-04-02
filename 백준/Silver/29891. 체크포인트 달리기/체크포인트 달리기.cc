#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
#define endl '\n'
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> plus, minus;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a > 0) plus.push_back(a);
        else minus.push_back((-1) * a);
    }
    sort(plus.begin(), plus.end());
    sort(minus.begin(), minus.end());

    long long res = 0;
    int idx = plus.size() - 1;
    while (idx >= 0) {
        res += 2 * plus[idx];
        idx -= k;
    }
    idx = minus.size() - 1;
    while (idx >=0) {
        res += 2 * minus[idx];
        idx -= k;
    }

    cout << res;
}