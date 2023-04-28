#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    double price[5] = {350.34, 230.90, 190.55, 125.30, 180.90};

    for (int i = 0; i < t; i++) {
        int arr[5];
        double res = 0;

        for (int j = 0; j < 5; j++) {
            cin >> arr[j];
            res += price[j] * arr[j];
        }

        cout.precision(2);
        cout << fixed;
        cout << '$' << res << '\n';
        


    }

    
}