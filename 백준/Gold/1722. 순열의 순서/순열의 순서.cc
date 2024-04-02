#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
#define pii pair<int, int>
using ll = long long;
using namespace std;

int n, q;
long f[21], s[21]; // factorial
bool visited[21] = {0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> q;

    f[0] = 1;
    for (int i = 1; i <= n; i++) f[i] = f[i - 1] * i; // 각 자릿수에서 만들 수 있는 경우의 수

    if (q == 1) {
        long k;
        cin >> k;

        for (int i = 1; i <= n; i++) {
            for (int j = 1, cnt = 1; j <= n; j++) {
                if (visited[j]) continue;

                if (k <= cnt * f[n - i]) { // 각 자리에 들어갈 수 있는 숫자 찾기
                    k -= ((cnt - 1) * f[n - i]);
                    s[i] = j;
                    visited[j] = true;
                    break;
                }

                cnt++; 
            }
        }

        for (int i = 1; i <= n; i++) cout << s[i] << ' ';
    }
    else {
        long k = 1;

        for (int i = 1; i <= n; i++) {
            cin >> s[i];

            long cnt = 0;
            for (int j = 1; j < s[i]; j++) {
                if (!visited[j]) cnt++; // 지금 수보다 작은 수 중에 미사용 숫자 개수 카운트
            }
            k += cnt * f[n - i];
            visited[s[i]] = true;
        }

        cout << k;
    }
}