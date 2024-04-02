#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
#define pii pair<int, int>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    char arr[10000];
    for (int i = 0; i < N; i++) cin >> arr[i];

    char hello;
    cin >> hello;

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if (arr[i] == hello) cnt++;
    }

    cout << cnt;


}