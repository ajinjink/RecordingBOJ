#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b, c;
    bool AP = false;

    cin >> a >> b >> c;

    while (!(a == 0 && b == 0 && c == 0)) {
        if (b - a == c - b) {
            AP = true;
        }

        int res;
        if (AP) {
            res = c + c - b;
            cout << "AP " << res << '\n';
        }
        else {
            res = c * c / b;
            cout << "GP " << res << '\n';
        }

        cin >> a >> b >> c;
        AP = false;

    }



}