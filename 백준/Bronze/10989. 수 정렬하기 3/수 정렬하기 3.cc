#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int count[10000] = {0};

    int N, temp;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> temp;
        count[temp - 1]++;
    }
    for (int i = 0; i < 10000; i++) {
        for (int j = 0; j < count[i]; j++) {
            cout << i + 1 << '\n';
        }
    }
}