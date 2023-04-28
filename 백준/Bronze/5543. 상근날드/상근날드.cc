#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int p[3];
    int drink[2];

    for (int i = 0; i < 3; i++) {
        cin >> p[i];
    }
    cin >> drink[0];
    cin >> drink[1];

    sort(p, p + 3);
    sort(drink, drink + 2);

    cout << p[0] + drink[0] - 50;
    
    
}

