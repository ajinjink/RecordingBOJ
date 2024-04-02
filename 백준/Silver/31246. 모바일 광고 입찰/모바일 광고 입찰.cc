#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <cstring>
#include <limits.h>
#define endl '\n'
#define pii pair<int, int>
#define tiiii tuple<int, int, int, int>
using ll = long long;
using namespace std;

// vector<pii> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    vector<int> v;
    int cnt = 0;

    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        if (a >= b) cnt++;
        else v.push_back(b - a);
    }

    sort(v.begin(), v.end());

    if (cnt >= K) cout << 0;
    else {
        cout << v[K - cnt - 1];
    }

}
