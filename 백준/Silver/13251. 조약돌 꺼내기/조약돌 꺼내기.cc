#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define endl '\n'
#define pii pair<int, int>S
using ll = long long;
using namespace std;

int n, m, k;
int d[51];
double p[51];
double res = 0.0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> m;

    for (int i = 0; i < m; i++) {
        cin >> d[i];
        n += d[i];
    }

    cin >> k;

    for (int i = 0; i <= m; i++) {
        if (d[i] >= k) {
            p[i] = 1.0;
            for (int j = 0; j < k; j++) p[i] *= (double)(d[i] - j) / (n - j);
        }
        res += p[i];
    }

    cout << fixed;
    cout.precision(9);
    cout << res;

}
