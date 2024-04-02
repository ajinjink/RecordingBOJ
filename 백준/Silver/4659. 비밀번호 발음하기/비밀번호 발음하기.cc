#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;

bool isvowel(char c) {
    char arr[5] = {'a', 'e', 'i', 'o', 'u'};

    for (int i = 0; i < 5; i++) {
        if (c == arr[i]) return true;
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string pw;
    cin >> pw;

    while (pw != "end") {
        bool safe = true;

        bool existsvowel = false;
        int vowelcnt = 0, consonantcnt = 0;
        char prev = 'A';

        for (int i = 0; i < pw.length(); i++) {
            if (isvowel(pw[i])) {
                existsvowel = true;
                consonantcnt = 0;
                vowelcnt++;
            }
            else {
                vowelcnt = 0;
                consonantcnt++;
            }
            if (vowelcnt == 3 || consonantcnt == 3) {
                safe = false;
                break;
            }

            if (pw[i] == prev) {
                if (pw[i] != 'e' && pw[i] != 'o') {
                    safe = false;
                    break;
                }
            }
            prev = pw[i];

        }

        if (!existsvowel) safe = false;

        if (safe) cout << "<" << pw << "> is acceptable." << endl;
        else cout << "<" << pw << "> is not acceptable." << endl;

        cin >> pw;
    }
}