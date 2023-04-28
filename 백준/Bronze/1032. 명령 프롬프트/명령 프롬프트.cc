#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    string arr[51];

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    if (N == 1) {
        cout << arr[0];
        return 0;
    }
    
    for (int i = 0; i < arr[0].length(); i++) {
        char first = arr[0][i];
        int flagdot = 0;
        if (first == '.') {
            flagdot = 1;
        }
        int flagalpha = 1;
        for (int j = 1; j < N; j++) {
            if (arr[j][i] != '.') {
                flagdot = 0;
            }
            if (arr[j][i] != first) {
                flagalpha = 0;
                break;
            }
        }
        if (flagdot == 1) {
            cout << ".";
        }
        else if (flagdot == 0 && flagalpha == 1) {
            cout << first;
        }
        else if (flagalpha == 0) {
            cout << "?";
        }
    }
}