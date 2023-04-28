#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(pair<int, int> &a, pair<int, int> &b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second < b.second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<pair<int, int> > v;

    int temp1, temp2;

    for (int i = 0; i < N; i++) {
        cin >> temp1 >> temp2;
        v.push_back(make_pair(temp1, temp2));
    }

    sort(v.begin(), v.end(), compare);

    int count = 1, index = 0;

    for (int i = 1; i < N; i++) {
        int end = v[index].second;
        if (v[i].first >= end) {
            count++;
            index = i;
        }

    }
    cout << count;


}