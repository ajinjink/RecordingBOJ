#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#define endl '\n'
#define pii pair<int, int>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, h;
    cin >> n >> h;

    int res = 0;
    while (n--) {
        int a;
        cin >> a;

        if (a <= h) res++;
    }

    cout << res;
}