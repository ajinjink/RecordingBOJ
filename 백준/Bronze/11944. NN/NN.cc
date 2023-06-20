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

    string n;
    int m;
    cin >> n >> m;
    int N = stoi(n);

    if (n.length() * N <= m) {
        for (int i = 0; i < N; i++) {
            cout << n;
        }
    }
    else {
        for (int i = 0; i < m; i++) {
            cout << n[i % n.length()];
        }
    }

    
}
