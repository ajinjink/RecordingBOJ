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
    
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        int fives = n / 5;
        int ones = n % 5;
        for (int j = 0; j < fives; j++) cout << "++++ ";
        for (int j = 0; j < ones; j++) cout << '|';
        cout << endl;
    }

}
