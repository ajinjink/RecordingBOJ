#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

bool compare(int a, int b) {
    return a > b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    char arr[10][10];
    int len[10] = {0};
    int alpha[26] = {0};

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        len[i] = strlen(arr[i]);
    }

    for (int i = 0; i < N; i++) {
        int temp = 1;
        for (int j = len[i] - 1; j >= 0; j--) {
            alpha[arr[i][j] - 'A'] += temp;
            temp *= 10;
        }
    }

    sort(alpha, alpha + 26, compare);
    int res = 0;
    for (int i = 0; i < 10; i++) {
        res += alpha[i] * (9 - i);
    }

    cout << res;
}