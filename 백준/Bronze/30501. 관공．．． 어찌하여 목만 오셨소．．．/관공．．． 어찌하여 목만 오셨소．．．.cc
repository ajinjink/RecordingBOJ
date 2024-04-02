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

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;

        for (int j = 0; j < name.length(); j++) {
            if (name[j] == 'S') {
                cout << name;
                return 0;
            }
        }
    }
}