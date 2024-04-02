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

    bool contain = false;
    string num = to_string(n);
    for (int i = 0; i < num.length(); i++) {
        if (num[i] == '7') contain = true;
    }

    if (!contain) {
        if (n % 7) cout << 0;
        else cout << 1;
    }
    else {
        if (n % 7) cout << 2;
        else cout << 3;
    }

}