#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
#define pii pair<int, int>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 15 * 15; i++) {
        char c;
        cin >> c;
        if (c == 'w') {
            cout << "chunbae";
            break;
        }
        else if (c == 'b') {
            cout << "nabi";
            break;
        }
        else if (c == 'g') {
            cout << "yeongcheol";
            break;
        }
    }
}