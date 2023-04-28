#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int k, n;
    cin >> k;

    for (int i = 0; i < k; i++) {
        cin >> n;
        for (int j = 0; j < n; j++) {
            cout << '=';
        }
        cout << '\n';
    }


}