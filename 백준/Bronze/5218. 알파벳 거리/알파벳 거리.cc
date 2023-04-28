#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, dist;
    cin >> T;
    string str1, str2;

    for (int i = 0; i < T; i++) {
        cin >> str1 >> str2;
        cout << "Distances: ";
        for (int j = 0; j < str1.length(); j++) {
            if (str2[j] >= str1[j]) {
                dist = str2[j] - str1[j];
            }
            else {
                dist = str2[j] + 26 - str1[j];
            }
            cout << dist << ' ';
        }
        cout << '\n';
    }
}

