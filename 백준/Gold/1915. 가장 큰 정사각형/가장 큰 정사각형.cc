#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
#define pii pair<int, int>
using ll = long long;
using namespace std;

int n, m;
int d[1001][1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        for (int j = 0; j < m; j++) d[i][j] = s[j] - '0';
    }

    long max = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (d[i][j] == 1 && j > 0 && i > 0)
                d[i][j] = min(d[i - 1][j - 1], min(d[i - 1][j], d[i][j - 1])) + d[i][j];
            if (max < d[i][j]) max = d[i][j];
        }
    }

    cout << max * max;
}