#include <iostream>
#include <string>
using namespace std;

int main() {
    int T, N;
    string temp;

    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N >> temp;
        int idx = 0;
        for (int j = 0; j < temp.length(); j++) {
            for (int k = 0; k < N; k++) {
                cout << temp[j];
            }
        }
        cout << '\n';
    }
}