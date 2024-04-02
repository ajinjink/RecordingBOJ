#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int res1 = 0, res2 = 0, res3 = 0;

    for (int i = 1; i <= n; i++) {
        res1 += i;
    }

    res2 = res1 * res1;
    
    for (int i = 1; i <= n; i++) {
        res3 += (i * i * i);
    }

    cout << res1 << '\n' << res2 << '\n' << res3;
}