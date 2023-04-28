#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    getline(cin, str);

    do {
        for (int i = str.length() - 1; i >= 0; i--) {
            cout << str[i];
        }
        cout << '\n';
        getline(cin, str);
    } while (str != "END");
}