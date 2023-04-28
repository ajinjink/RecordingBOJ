#include <iostream>
using namespace std;

int arr[64][64];

bool check (int row, int col, int n) {
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
        cout << arr[row][col];
    }
    else {
        cout << "(";
        int size = n / 2;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                divide(row + i * size, col + j * size, size);
            }
        }
        cout << ")";
    }
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    string temp;

    for (int i = 0; i < N; i++) {
        cin >> temp;
        for (int j = 0; j < N; j++) {
            arr[i][j] = (int)temp[j] - 48;
        }
    }

    divide(0, 0, N);
}
