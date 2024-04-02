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
        int year;
        cin >> year;
        int div = year % 100;
        if ((year + 1) % div == 0) cout << "Good" << endl;
        else cout << "Bye" << endl;
    }
}