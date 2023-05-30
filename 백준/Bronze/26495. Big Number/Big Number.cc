#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int zero[5][4] = {{0,0,0,0},{0,10,10,0},{0,10,10,0},{0,10,10,0},{0,0,0,0}};
    int one[5][4] = {{10,10,10,1},{10,10,10,1},{10,10,10,1},{10,10,10,1},{10,10,10,1}};
    int two[5][4] = {{2,2,2,2},{10,10,10,2},{2,2,2,2},{2,11,11,11},{2,2,2,2}};
    int three[5][4] = {{3,3,3,3},{10,10,10,3},{3,3,3,3},{10,10,10,3},{3,3,3,3}};
    int four[5][4] = {{4,10,10,4},{4,10,10,4},{4,4,4,4},{10,10,10,4},{10,10,10,4}};
    int five[5][4] = {{5,5,5,5},{5,11,11,11},{5,5,5,5},{10,10,10,5},{5,5,5,5}};
    int six[5][4] = {{6,6,6,6},{6,11,11,11},{6,6,6,6},{6,10,10,6},{6,6,6,6}};
    int seven[5][4] = {{7,7,7,7},{10,10,10,7},{10,10,10,7},{10,10,10,7},{10,10,10,7}};
    int eight[5][4] = {{8,8,8,8},{8,10,10,8},{8,8,8,8},{8,10,10,8},{8,8,8,8}};
    int nine[5][4] = {{9,9,9,9},{9,10,10,9},{9,9,9,9},{10,10,10,9},{10,10,10,9}};

    string num;
    cin >> num;

    for (int i = 0; i < num.length(); i++) {
        if (num[i] == '0') {
            for (int j = 0; j < 5; j++) {
                for (int k = 0; k < 4; k++) {
                    if (zero[j][k] == 10) {
                        cout << ' ';
                    }
                    else {
                        cout << zero[j][k];
                    }
                }
                cout << '\n';
            }
        }
        if (num[i] == '1') {
            for (int j = 0; j < 5; j++) {
                for (int k = 0; k < 4; k++) {
                    if (one[j][k] == 10) {
                        cout << ' ';
                    }
                    else {
                        cout << one[j][k];
                    }
                }
                cout << '\n';
            }
        }
        if (num[i] == '2') {
            for (int j = 0; j < 5; j++) {
                for (int k = 0; k < 4; k++) {
                    if (two[j][k] == 10) {
                        cout << ' ';
                    }
                    else if (two[j][k] == 11) {
                        ;
                    }
                    else {
                        cout << two[j][k];
                    }
                }
                cout << '\n';
            }
        }
        if (num[i] == '3') {
            for (int j = 0; j < 5; j++) {
                for (int k = 0; k < 4; k++) {
                    if (three[j][k] == 10) {
                        cout << ' ';
                    }
                    else {
                        cout << three[j][k];
                    }
                }
                cout << '\n';
            }
        }
        if (num[i] == '4') {
            for (int j = 0; j < 5; j++) {
                for (int k = 0; k < 4; k++) {
                    if (four[j][k] == 10) {
                        cout << ' ';
                    }
                    else {
                        cout << four[j][k];
                    }
                }
                cout << '\n';
            }
        }
        if (num[i] == '5') {
            for (int j = 0; j < 5; j++) {
                for (int k = 0; k < 4; k++) {
                    if (five[j][k] == 10) {
                        cout << ' ';
                    }
                    else if (five[j][k] == 11) {
                        ;
                    }
                    else {
                        cout << five[j][k];
                    }
                }
                cout << '\n';
            }
        }
        if (num[i] == '6') {
            for (int j = 0; j < 5; j++) {
                for (int k = 0; k < 4; k++) {
                    if (six[j][k] == 10) {
                        cout << ' ';
                    }
                    else if (six[j][k] == 11) {
                        ;
                    }
                    else {
                        cout << six[j][k];
                    }
                }
                cout << '\n';
            }
        }
        if (num[i] == '7') {
            for (int j = 0; j < 5; j++) {
                for (int k = 0; k < 4; k++) {
                    if (seven[j][k] == 10) {
                        cout << ' ';
                    }
                    else {
                        cout << seven[j][k];
                    }
                }
                cout << '\n';
            }
        }
        if (num[i] == '8') {
            for (int j = 0; j < 5; j++) {
                for (int k = 0; k < 4; k++) {
                    if (eight[j][k] == 10) {
                        cout << ' ';
                    }
                    else {
                        cout << eight[j][k];
                    }
                }
                cout << '\n';
            }
        }
        if (num[i] == '9') {
            for (int j = 0; j < 5; j++) {
                for (int k = 0; k < 4; k++) {
                    if (nine[j][k] == 10) {
                        cout << ' ';
                    }
                    else {
                        cout << nine[j][k];
                    }
                }
                cout << '\n';
            }
        }
        if (i != num.length() - 1) {
            cout << '\n';

        }

    
    }


}