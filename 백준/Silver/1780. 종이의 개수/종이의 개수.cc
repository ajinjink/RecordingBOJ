#include <iostream>
using namespace std;

int arr[2190][2190];
int res[3]; // -1 0 1 -> 0 1 2

bool check(int row, int col, int n) {
    for (int i = row; i < row + n; i++) {
        for (int j = col; j < col + n; j++) {
            if (arr[row][col] != arr[i][j]) {
                return false;
            }
        }
    }
    return true;
}

void divide (int row, int col, int n) {
    if (check(row, col, n)) {
        res[arr[row][col]]++;
    }
    else {
        int size = n / 3;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                divide(row + i * size, col + j * size, size);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, temp;
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> temp;
            arr[i][j] = temp + 1;
        }
    }

    divide(0, 0, N);

    cout << res[0] << '\n' << res[1] << '\n' << res[2];
}