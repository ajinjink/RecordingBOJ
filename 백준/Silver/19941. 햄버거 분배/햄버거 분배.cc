#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#define endl '\n'
#define pii pair<int, int>
using ll = long long;
using namespace std;

int p[20000] = {0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    char arr[20001];
    cin >> arr;

    for (int i = 0; i < N; i++) {
        if (arr[i] == 'P') {
            for (int j = i - K; j <= i + K; j++) {
                if (j < 0 || j >= N) continue;
                if (arr[j] == 'H' && p[j] == 0) {
                    p[j] = 1;
                    break;
                }
            }
        }
    }

    int res = 0;
    for (int i = 0; i < N; i++) res += p[i];

    cout << res;

}
