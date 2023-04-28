#include <iostream>
#include <cmath> 
using namespace std;

int N, r, c;
int ans = 0;

void divide (int row, int col, int size) {
    if (col == c && row == r) {
        cout << ans;
        return;
    }
    else if (r < row + size && r >= row && c < col + size && c >= col) {
        divide(row, col, size / 2);
        divide(row, col + size / 2, size / 2);
        divide(row + size / 2, col, size / 2);
        divide(row + size / 2, col + size / 2, size / 2);
    }
    else {
        ans += size * size;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> r >> c;

    divide(0, 0, pow(2, N));
}