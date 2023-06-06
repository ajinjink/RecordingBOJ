#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int s;
        cin >> s;
        int n, p, q;
        long res = 0;
        cin >> n;
        while (n--) {
            cin >> q >> p;
            res += q * p;
        }
        cout << s + res << '\n';
    }
}
