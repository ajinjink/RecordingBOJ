#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        string num;
        cin >> num;
        long long sum = 0;
        for (int j = 0; j < 24; j++) {
            if (num[j] == '1') {

                sum += pow(2, 23 - j);
            }
        }
        cout << sum << '\n';
    }
}