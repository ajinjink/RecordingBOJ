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
        // for (int j = 0; j < name.length(); j++) {
        //     cout << tolower(name[j]);
        // }
        transform(name.begin(), name.end(), name.begin(), ::tolower);
        cout << name << '\n';
    }

    
}
