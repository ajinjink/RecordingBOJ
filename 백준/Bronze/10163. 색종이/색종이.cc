#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    int table[1001][1001]= {0,};

    int x1, y1, x2, y2;
    for (int t = 0; t < N; t++) {
        cin >> x1 >> y1 >> x2 >> y2;
        for (int i = x1; i < x1 + x2; i++) {
            for (int j = y1; j < y1 + y2; j++) {
                table[i][j] = t + 1;
            }
        }
    }

    int arr[101] = {0};
    for (int i = 0; i < 1001; i++) {
        for (int j = 0; j < 1001; j++) {
            if (table[i][j]) {
                arr[table[i][j]]++;
            };
        }
    }



    for (int i = 1; i <= N; i++) {
        cout << arr[i] << '\n';
    }


}







