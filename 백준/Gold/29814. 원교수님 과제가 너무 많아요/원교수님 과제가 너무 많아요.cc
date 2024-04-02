#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int N, C;
    cin >> N >> C;

    vector<pair<int, int> > v;
    for (int i = 0; i < N; i++) {
        int d, t, p;
        cin >> d >> t >> p; // 마감일, 과제 점수
        v.push_back(make_pair(d - t + 1, p));
    }
    sort(v.begin(), v.end()); // 마감일 오름차순

    // 수행한 과제
    priority_queue<int, vector<int>, greater<>> pq; // 점수 오름차순

    int sum = 0;
    for (int i = 0; i < N; i++){
        pq.push(v[i].second);
        sum += v[i].second;
        if (pq.size() > v[i].first) {
            sum -= pq.top();
            pq.pop();
        }
    }

    if (sum < C) cout << "I'm sorry professor Won!";
    else {
        while (sum - pq.top() >= C) {
            sum -= pq.top();
            pq.pop();
        } 
        cout << pq.size();
    }

}