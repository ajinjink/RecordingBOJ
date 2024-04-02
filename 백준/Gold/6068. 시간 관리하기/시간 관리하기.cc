#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
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

    vector<pii> v;

    for (int i = 0; i < n; i++) {
        int d, t;
        cin >> d >> t;
        v.push_back({t, d}); // 듀, 걸리는 시간
    }
    sort(v.rbegin(), v.rend());
    // for (int i = 0; i < n; i++) cout << v[i].first;
    int now = v[0].first - v[0].second;
    for (int i = 1; i < n; i++) {
        int due = v[i].first; 
        int days = v[i].second; 
        if (now >= due) now = due - days;
        else now -= days;
    }

    if (now < 0) cout << -1;
    else cout << now;
}
