#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    string name;
    for (int i = 0; i < n; i++) {
        cin >> name;
        cout << "String #" << i + 1 << "\n";
        for (int j = 0; j < name.length(); j++) {
            if (name[j] == 90) {
                cout << 'A';
                continue;
            }
            cout << (char)(name[j] + 1);
        }
        cout << "\n\n";
    }

    // cout << (int) 'A' << (int)'Z';


}