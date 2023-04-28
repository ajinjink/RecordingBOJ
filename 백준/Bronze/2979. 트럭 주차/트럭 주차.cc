#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int A, B, C, res = 0;
    cin >> A >> B >> C;
    int arr[101] = {0};

    for (int i = 0; i < 3; i++) {
        int s, e;
        cin >> s >> e;
        for (int j = s; j < e; j++) {
            arr[j]++;
        }
    }
    for (int i = 0; i < 101; i++) {
        if (arr[i] == 1) {
            res += A;
        }
        else if (arr[i] == 2) {
            res += B * 2;
        }
        else if (arr[i] == 3) {
            res += C * 3;
        }
    }

    cout << res;

}