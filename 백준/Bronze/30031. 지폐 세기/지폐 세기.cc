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
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        switch (a)
        {
        case 136:
            res += 1000;
            break;
        case 142:
            res += 5000;
            break;
        case 148:
            res += 10000;
            break;
        case 154:
            res += 50000;
            break;
        
        default:
            break;
        }
    }

    cout << res;
}