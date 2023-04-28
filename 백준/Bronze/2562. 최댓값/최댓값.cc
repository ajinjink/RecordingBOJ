#include <iostream>
using namespace std;

int main() {
    int num[9];

    int max = 0, index = 0;

    for (int i = 0; i < 9; i++) {
        cin >> num[i];
        if (num[i] > max) {
            max = num[i];
            index = i + 1;
        }
    }

    cout << max << '\n' << index;
}