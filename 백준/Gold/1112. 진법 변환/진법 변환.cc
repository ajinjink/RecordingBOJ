#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int x, b;
    cin >> x >> b;

    char n[100];

    int xx;
    if (b > 0) {
        xx = fabs(x);
    }
    else {
        xx = x;
    }

    int ind = 0, temp;
    while (xx != 0) {
        int temp = xx % (int)fabs(b);
        if (temp < 0) {
            temp += fabs(b);
        }
        xx = (xx - temp) / b;
        n[ind++] = temp + '0';
    }
    if (ind == 0) {
        n[ind++] = '0';
        n[ind] = 0;
    }

    if (b > 0 && x < 0) {
        cout << '-';
    }
    
    for (int i = ind - 1; i >= 0; i--) {
        cout << n[i];
    }
}