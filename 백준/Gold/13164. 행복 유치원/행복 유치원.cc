#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    vector<int> v(N); // 키 배열
    vector<int> sep; // 팀 나눠지는 구간
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < N - 1; i++) {
        sep.push_back(v[i + 1] - v[i]);
    }

    sort(sep.begin(), sep.end());

    int res = 0;
    for (int i = 0; i < sep.size() - (K - 1); i++) {
        res += sep[i];
    }

    cout << res;

}