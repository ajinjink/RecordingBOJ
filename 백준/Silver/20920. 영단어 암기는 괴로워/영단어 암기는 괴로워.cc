#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#define endl '\n'
#define pii pair<int, int>
using ll = long long;
using namespace std;

map<string, int> m;
vector<pair<string, int>> v;

bool compare(pair<string, int> a, pair<string, int> b) {
    if (a.first.length() == b.first.length() && a.second == b.second) return a.first < b.first;
    if (a.second == b.second) return a.first.length() > b.first.length();
    return a.second > b.second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        if (s.length() >= M) {
            if (m.find(s) != m.end()) m[s]++;
            else m.insert({s, 1});
        }
    }

    v.resize(m.size());
    transform(m.begin(), m.end(), v.begin(), 
                   [](const std::pair<const std::string, int>& p) {
                       return std::make_pair(p.first, p.second);
                   });
    sort(v.begin(), v.end(), compare);

    for (int i = 0; i < v.size(); i++) cout << v[i].first << endl;
}
