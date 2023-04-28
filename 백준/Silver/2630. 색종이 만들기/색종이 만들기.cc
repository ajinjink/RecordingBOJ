#include <iostream>
using namespace std;

int arr[130][130];
int res[2] = {0}; // 0 white, 1 blue

bool check(int row, int col, int n) { // same color?
    for (int i = row; i < row + n; i++) {
        for (int j = col; j < col + n; j++) {
            if (arr[i][j] != arr[row][col]) {
                return false;
            }
        }
    }
    return true;
}

void divide(int row, int col, int n) {
    if (check(row, col, n)) {
        int color = arr[row][col];
        res[color]++;
    }
    else {
        int size = n / 2;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                divide(row + i * size, col + j * size, size);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    divide(0, 0, N);

    cout << res[0] << '\n' << res[1];
}