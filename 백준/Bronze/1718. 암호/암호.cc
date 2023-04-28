#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string PT, key;
    getline(cin, PT);
    cin >> key;

    for (int i = 0; i < PT.length(); i++) {
        if (PT[i] != 32) {
            if (PT[i] > key[i % key.length()]) {
                PT[i] -= (key[i % key.length()] - 96);

            }
            else {
                PT[i] = PT[i] + 26 - (key[i % key.length()] - 96);
            }
            
        }

    }

    for (int i = 0; i < PT.length(); i++) {
        cout << PT[i];
    }

}