#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
#define pii pair<int, int>
using ll = long long;
using namespace std;

int n;
int score[10001] = {0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    for (int i = 0; i < n; i++) cin >> score[i];

    sort(score, score + n);

    int total = 0;
    for (int i = 0; i < n; i++) {
        total += score[i];
        if (total < (i + 1) * i / 2) {
            cout << -1;
            return 0;
        }
    }

    if (total == n * (n - 1) / 2) cout << 1;
    else cout << -1;


}