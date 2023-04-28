#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, temp, res, lower, upper;
    cin >> N;

    vector<int> v;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end());
    
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> temp;
        lower = lower_bound(v.begin(), v.end(), temp) - v.begin();
        upper = upper_bound(v.begin(), v.end(), temp) - v.begin();
        cout << upper - lower << ' ';
    }
}