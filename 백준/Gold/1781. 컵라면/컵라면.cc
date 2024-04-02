#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}

struct compare2 {
    bool operator() (pair<int, int> a, pair<int, int> b) {
        if (a.second == b.second) return a.first > b.first;
        return a.second > b.second;
    }
};

int main() {
    int N;
    cin >> N;

    vector<pair<int, int> > v;
    for (int i = 0; i < N; i++) {
        int d, w;
        cin >> d >> w;
        v.push_back(make_pair(d, w));
    }
    sort(v.begin(), v.end(), compare);

    priority_queue<pair<int, int>, vector<pair<int, int> >, compare2> pq;

    long long res = 0, day = 1;
    for (int i = 0; i < N; i++) { 
        while (!pq.empty() && v[i].first < day) { 
            if (pq.top().second > v[i].second) break;
            res -= pq.top().second;
            pq.pop();
            day--;
        }
       
        if (v[i].first >= day) {
            res += v[i].second;
            pq.push(v[i]);
            day++;
        }
    }

    cout << res;

}