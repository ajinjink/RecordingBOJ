#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
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
    cin.ignore();

    while (n--) {
        string s;
        getline(cin, s);

        if (s[s.length() - 1] != '.') cout << s << '.' << endl;
        else cout << s << endl;
    }
    

}