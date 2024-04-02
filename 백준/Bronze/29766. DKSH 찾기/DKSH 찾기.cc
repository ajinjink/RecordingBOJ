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

    string s;
    cin >> s;

    if (s.length() < 4) {
        cout << 0;
        return 0;
    }

    int res = 0;
    for (int i = 0; i < s.length() - 3; i++) {
        if (s.substr(i, 4) == "DKSH") res++;
    }

    cout << res;
}