#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
}

int main() {
    int N;
    cin >> N;

    int days[1001] = {0};

    vector<pair<int, int> > v;
    for (int i = 0; i < N; i++) {
        int d, w; // 마감일, 과제 점수
        cin >> d >> w;
        v.push_back(make_pair(d, w));
    }
    sort(v.begin(), v.end(), compare); // 과제 점수 내림차순

    for (int i = 0; i < N; i++) { // 점수가 높은 과제부터
        for (int j = v[i].first; j > 0; j--) { // 마감일부터 하루씩 당기면서 비어있는 날에 과제 수행
            if (days[j] == 0) { // 그 과제를 최대한 마감일 가까이, 늦게 하고 싶음
                days[j] = v[i].second;
                break;
            }
        }
    }

    long res = 0;
    for (int i = 1; i <= 1000; i++) res += days[i];

    cout << res;
}