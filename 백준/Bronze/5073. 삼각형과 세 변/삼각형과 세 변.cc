#include <iostream>
#include <algorithm>
#define endl '\n'
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b, c;
    cin >> a >> b >> c;

    while (a && b && c) {
        int sum = a + b + c;
        if (max(a, max(b, c)) >= sum - max(a, max(b, c))) {
            cout << "Invalid" << endl;
            cin >> a >> b >> c;
            continue;
        }

        if (a == b && b == c) cout << "Equilateral" << endl;
        else if (a == b || b == c || c == a) cout << "Isosceles" << endl;
        else cout << "Scalene" << endl;

        cin >> a >> b >> c;
    }
}