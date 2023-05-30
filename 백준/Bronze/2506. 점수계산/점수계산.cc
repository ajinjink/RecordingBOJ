#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int count = 1, res = 0, temp;

    for (int i = 0; i < N; i++) {
        cin >> temp;
        if (temp) {
            res += count;
            count++;
        }
        else {
            count = 1;
        }
    }

    cout << res;
}
