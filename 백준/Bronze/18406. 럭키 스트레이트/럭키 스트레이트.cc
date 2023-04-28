#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string num;
    cin >> num;
    int front = 0, back = 0;
    int digit = num.length();

    for (int i = 0; i < digit / 2; i++) {
        front += num[i];
        back += num[digit/2 + i];
    }

    if (front == back) {
        cout << "LUCKY";
    }
    else {
        cout << "READY";
    }
    


}







