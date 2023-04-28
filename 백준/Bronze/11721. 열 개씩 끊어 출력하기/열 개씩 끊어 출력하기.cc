#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    cin >> str;

    int charcount = 0;
    
    for (int row = 0; row < 10; row++) {
        for (int i = 0; i < 10; i++) {
            if (charcount == str.length()) {
                return 0;
            }
            cout << str[(row * 10) + i];
            charcount++;
        }
        cout << '\n';
    }

}