#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

bool comp (pair<int, int> &a, pair<int, int> &b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second > b.second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, temp;
    double sum = 0;
    cin >> N;

    vector<int> v;

    for (int i = 0; i < N; i++) {
        cin >> temp;
        sum += temp;
        v.push_back(temp);
    }

    sort(v.begin(), v.end());
    
    cout << (int)floor((sum / N) + 0.5) << '\n';

    cout << v[N/2] << '\n';

    vector< pair<int, int> > vv;

    int temp2;

    for (int i = 0; i < N; i++) {
        if (vv.empty()) {
            vv.push_back(make_pair(v[i], 1));
        }
        else {
            if (temp2 == v[i]) {
                vv[vv.size() - 1].second++;
            }
            else {
                vv.push_back(make_pair(v[i], 1));
            }
        }
        temp2 = v[i];
    }

    sort(vv.begin(), vv.end(), comp);

    if (vv.size() > 1) {
        if (vv[0].second == vv[1].second) {
            cout << vv[1].first << '\n';
        }
        else {
            cout << vv.front().first << '\n';
        }
    }
    else {
        cout << vv.front().first << '\n';
    }

    cout << v.back() - v.front();

}