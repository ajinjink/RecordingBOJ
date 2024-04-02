#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <cstring>
#include <sstream>
#include <limits.h>
#define endl '\n'
#define pii pair<int, int>
#define tiiii tuple<int, int, int, int>
using ll = long long;
using namespace std;

bool compare(pair<int, string> a, pair<int, string> b) {
    return a.second < b.second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int p, m;
    cin >> p >> m;

    vector<vector<pair<int, string>>> v(p + 1);

    for (int i = 0; i < p; i++) {
        int l;
        string n;
        cin >> l >> n;

        bool flag = true;
        for (int j = 0; j < i; j++) {
            if (v[j].size() < m && v[j].size() > 0) {
                if (abs(v[j][0].first - l) <= 10) {
                    v[j].push_back({l, n});
                    flag = false;
                    break;
                }
            }
        }

        if (flag) v[i].push_back({l, n});

    }

    for (int i = 0; i < p; i++) {
        if (v[i].empty()) continue;
        if (v[i].size() == m) cout << "Started!" << endl;
        else if (v[i].size() < m) cout << "Waiting!" << endl;

        sort(v[i].begin(), v[i].end(), compare);

        for (int j = 0; j < v[i].size(); j++) {
            cout << v[i][j].first << ' ' << v[i][j].second << endl;
        }
    }
    
}

