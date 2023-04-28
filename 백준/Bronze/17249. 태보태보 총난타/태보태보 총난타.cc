#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;

    cin >> str;
    int res1 = 0, res2 = 0, face = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '^') {
            face = 1;
        }
        if (str[i] == '@' && face == 0) {
            res1++;
        }
        if (str[i] == '@' && face == 1) {
            res2++;
        }
    }

    cout << res1 << ' ' << res2;
    

}