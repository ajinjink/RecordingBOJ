#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<pair<int, int> > v;

    while (N--) {
        int a, b;
        cin >> a >> b; // 소요시간, 듀
        v.push_back(make_pair(b, a));
    }
    sort(v.begin(), v.end());

    int late = 0;
    while (1) {
        int sum = late;
        for (int i = 0; i < v.size(); i++) {
            if (sum + v[i].second <= v[i].first) sum += v[i].second;
            else {
                cout << late - 1;
                return 0;
            }
        }
        late += 1;
    }

}