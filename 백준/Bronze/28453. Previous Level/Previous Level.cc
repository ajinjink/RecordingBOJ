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

    while (n--) {
        int m;
        cin >> m;

        if (m >= 300) cout << 1 << ' ';
        else if (m >= 275) cout << 2 << ' ';
        else if (m >= 250) cout << 3 << ' ';
        else cout << 4 << ' ';
    }

}