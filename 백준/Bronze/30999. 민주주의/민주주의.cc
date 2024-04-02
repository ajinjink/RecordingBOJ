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

    int n, m;
    cin >> n >> m;

    int res = 0;
    for (int i = 0; i < n; i++) {
        string ox;
        cin >> ox;

        int temp = 0;
        for (int j = 0; j < ox.length(); j++) {
            if (ox[j] == 'O') temp++;
        }

        if (temp > ox.length() / 2) res++;
    }

    cout << res;
}