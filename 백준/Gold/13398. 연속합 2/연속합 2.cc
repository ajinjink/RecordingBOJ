#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define endl '\n'
#define pii pair<int, int>
using ll = long long;
using namespace std;

int N;
vector<int> arr, l, r;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    arr.resize(N);
    l.resize(N);
    r.resize(N);

    for (int i = 0; i < N; i++) cin >> arr[i];

    l[0] = arr[0];
    int res = l[0];
    for (int i = 1; i < N; i++) {
        l[i] = max(l[i - 1] + arr[i], arr[i]); // 왼쪽에서부터 연속합
        res = max(res, l[i]); // 최대 연속함
    }

    r[N - 1] = arr[N - 1];
    for (int i = N - 2; i >= 0; i--) {
        r[i] = max(r[i + 1] + arr[i], arr[i]); // 오른쪽에서부터 연속합
    }

    for (int i = 1; i < N - 1; i++) { // i번째 제외하고
        int temp = l[i - 1] + r[i + 1]; // 왼쪽 오른쪽 연속합 더함
        res = max(res, temp);
    }

    cout << res;
}