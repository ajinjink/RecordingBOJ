#include <iostream>
#include <algorithm>
#include <cmath>
#define endl '\n'
#define pii pair<int, int>
using ll = long long;
using namespace std;

int x, y;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin >> t;

    while (t--) {
        cin >> x >> y;
        int dist = y - x;
        int rtd = sqrt(dist) / 1;

        int res;
        if (pow(rtd, 2) == dist) res = 2 * rtd - 1;
        else res = 2 * rtd;

        if (dist > rtd * (rtd + 1)) res++;

        cout << res << endl;
    }


}