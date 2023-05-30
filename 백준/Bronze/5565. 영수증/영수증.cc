#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int total, temp;
    cin >> total;

    for (int i = 0; i < 9; i++) {
        cin >> temp;
        total -= temp;
    }

    cout << total;
    

}