#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
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

    int row = 1, cnt = 1;
    for (int i = 1; cnt < N; i++) {
        cnt += 6 * i;
        row++;
    }

    cout << row;
}