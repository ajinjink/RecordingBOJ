#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    int mindist[101][101];

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> mindist[i][j];
        }
    }

    for (int k = 0; k < N; k++) { // floyd-warshall
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (mindist[i][k] == 1 && mindist[k][j] == 1) {
                    mindist[i][j] = 1;
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << mindist[i][j] << ' ';
        }
        cout << '\n';
    }

}