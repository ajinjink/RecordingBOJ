#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int row = 1, col, sum = 1;
    int X;
    cin >> X;

    if (X == 1) {
        cout << "1/1";
        return 0;
    }

    for (int i = 2; i < 4500; i++) {
        if (sum + i < X) {
            sum += i;
            
        }
        else {
            row = i;
            col = X - sum;
            break;
        }
    }
    if (row % 2 == 0) {
        cout << col << '/' << row + 1 - col;
    }
    else {
        cout << row + 1 - col << '/' << col;
    }

}

