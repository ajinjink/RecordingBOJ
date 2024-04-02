#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
#define pii pair<int, int>
using ll = long long;
using namespace std;

int T, N, M;
int A[1000];
int B[1000];
vector<int> suma, sumb;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
    cin >> M;
    for (int i = 0; i < M; i++) cin >> B[i];

    for (int i = 0; i < N; i++) { // A의 부분합 저장
        int sum = 0;
        for (int j = i; j < N; j++) {
            sum += A[j];
            suma.push_back(sum);
        }
    }
    for (int i = 0; i < M; i++) { // B의 부분합 저장
        int sum = 0;
        for (int j = i; j < M; j++) {
            sum += B[j];
            sumb.push_back(sum);
        }
    }
    sort(suma.begin(), suma.end());
    sort(sumb.begin(), sumb.end());

    ll cnt = 0;
    for (int i = 0; i < suma.size(); i++) {
        int findb = T - suma[i];
        auto ub = upper_bound(sumb.begin(), sumb.end(), findb);
        auto lb = lower_bound(sumb.begin(), sumb.end(), findb);
        cnt += ub - lb;
    }

    cout << cnt;
}