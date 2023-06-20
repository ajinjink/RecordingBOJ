#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int count;
        if (n % 2 == 0) {
            count = n / 2 - 1;
        }
        else {
            count = n / 2;
        }
        cout << "Pairs for " << n << ": ";

        for (int i = 1; i <(double)n / 2; i++) {
            cout << i << ' ' << n - i;
            if (--count) {
                cout << ", ";
            }
        }
        cout << '\n';

    }

    
}
