#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int K;
    cin >> K;

    vector<pair<int, int> > v(46);
    v[0] = make_pair(1, 0);
    v[1] = make_pair(0, 1);
    v[2] = make_pair(1, 1);
    for (int i = 3; i <= K; i++) {
        v[i].first = v[i - 1].second;
        v[i].second = v[i - 1].first + v[i - 1].second;
    }

    cout << v[K].first << ' ' << v[K].second;

}