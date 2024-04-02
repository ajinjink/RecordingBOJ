#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
#define pii pair<int, int>
using ll = long long;
using namespace std;

vector<int> pattern;
int pi[1000001] = {0};

void make_pi() {
    int i = 0;
    for (int j = 1; j < pattern.size(); j++) {
        while (i > 0 && pattern[i] != pattern[j]) {
            i = pi[i - 1];
        }
        if (pattern[i] == pattern[j]) {
            i++;
            pi[j] = i;
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    pattern.resize(N);
    for (int i = N - 1; i >= 0; i--) cin >> pattern[i];

    make_pi();

    int maxnum = 0;
    for (int i = 0; i < N; i++) maxnum = max(maxnum, pi[i]);

    if (maxnum == 0) {
        cout << -1;
        return 0;
    }

    int maxcnt = 0;
    for (int i = N - 1; i >= 0; i--) {
        if (pi[i] == maxnum) maxcnt++;
    }

    cout << maxnum << ' ' << maxcnt;
}