#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(pair<string, int> &a, pair<string, int> &b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second > b.second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;

    vector<pair<string, int> > v;
    string title;

    for (int i = 0; i < N; i++) {
        cin >> title;
        bool flag = false;
        for (int j = 0; j < v.size(); j++) {
            if (title == v[j].first) {
                flag = true;
                v[j].second++;
            }
        }
        if (flag == false) {
            v.push_back(make_pair(title, 1));
        }
    }
    sort(v.begin(), v.end(), compare);

    cout << v[0].first;
}