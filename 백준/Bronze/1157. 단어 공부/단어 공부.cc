#include <iostream>
#include <algorithm>
#include <map>
#define endl '\n'
#define pii pair<int, int>
using ll = long long;
using namespace std;

map<char, int> m;

bool compare(pair<char, int> a, pair<char, int> b) {
    return a.second > b.second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin >> s;

    for (int i = 0; i < s.length(); i++) {
        if (97 <= s[i]) s[i] -= 32;

        if (m.find(s[i]) != m.end()) {
            m[s[i]]++;
        }
        else {
            m.insert({s[i], 1});
        }
    }

    vector<pair<char, int>> v;
    std::transform(m.begin(), m.end(), std::back_inserter(v),
                   [](const std::pair<char, int>& p) { return p; });

    sort(v.begin(), v.end(), compare);

    if (v.size() > 1 && v[0].second == v[1].second) cout << '?';
    else cout << v[0].first;

}