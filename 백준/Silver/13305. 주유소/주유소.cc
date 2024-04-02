#include <iostream>
#include <algorithm>
#include <queue>
#define endl '\n'
#define pii pair<int, int>
using ll = long long;
using namespace std;

ll dist[100001];
ll price[100001];
ll res[100001] = {0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    for (int i = 1; i <= N - 1; i++) cin >> dist[i]; // i - 1부터 i번째까지 거리
    for (int i = 0; i < N; i++) cin >> price[i]; // i번째 도시에서 기름값

    ll minprice = price[0];
    for (int i = 1; i < N; i++) {
        if (minprice > price[i - 1]) minprice = price[i - 1];
        res[i] = res[i - 1] + minprice * dist[i];
    }

    cout << res[N - 1];
}
