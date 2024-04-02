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
        string s;
        cin >> s;

        for (int i = 0; i < s.length() - 1; i++) {
            if (s.substr(i, 2) == "01" || s.substr(i, 2) == "OI") {
                res++;
                break;
            }
        }
    }

    cout << res;

}