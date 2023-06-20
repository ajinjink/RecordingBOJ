#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string id, f = ":fan:";
    cin >> id;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == 1 && j == 1) {
                cout << ':' << id << ':';
            }
            else {
                cout << f;
            }
        }
        cout << '\n';
    }
    
}
