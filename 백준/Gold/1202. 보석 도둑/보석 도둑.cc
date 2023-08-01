#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

bool comparePair(pair<int, int> a, pair<int, int> b) {
    if (a.second > b.second) {
        return false;
    }
    return true;
}

vector<int> bag;
vector<pair<int, int> > v;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K, maxw;
    cin >> N >> K;

    bag.resize(K);
    v.resize(N);

    priority_queue<int > pq; // 보석 가격 내림차순

    for (int i = 0; i < N; i++) {
        cin >> v[i].first >> v[i].second; // 무게, 가격
    }
    sort(v.begin(), v.end()); // 보석 무게 오름차순

    for (int i = 0; i < K; i++) {
        cin >> bag[i];
    }
    sort(bag.begin(), bag.end()); // 가방 무게 오름차순

    int index = 0;
    long long res = 0;

    for (int i = 0; i < K; i++) {
        int weight = bag[i];

        while (index < N && v[index].first <= weight) {
            pq.push(v[index++].second); // 현재 가방 수용 무게보다 작은 보석들
        }

        if (!pq.empty()) {
            res += pq.top(); // 가장 비싼 보석
            pq.pop();
        }
    }

    cout << res;



}