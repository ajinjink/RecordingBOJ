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

    int n1, n2, k1, k2;
    cin >> n1 >> k1 >> n2 >> k2;

    cout << n1 * k1 + n2 * k2;
}
