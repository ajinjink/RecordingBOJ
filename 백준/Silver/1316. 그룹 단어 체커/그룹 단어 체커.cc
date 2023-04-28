#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int alpha[27] = {0};
    char prev;
    string str;
    int T, res = 0, flag;

    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> str;
        prev = str[0];
        flag = 1;
        for (int j = 0; j < 27; j++) {
            alpha[j] = 0;
        }
        for (int j = 0; j < str.length(); j++) {
            if (str[j] != prev && alpha[str[j] - 97] == 1) {
                flag = 0;
            }
            else {
                alpha[str[j] - 97] = 1;
                prev = str[j];
            }
        }
        if (flag == 1) {
            res++;
        }
    }

    cout << res;
}

