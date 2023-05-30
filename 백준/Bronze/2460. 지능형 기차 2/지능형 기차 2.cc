#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int in, out;
    int total = 0, maxnum = 0;

    for (int i = 0; i < 10; i++) {
        cin >> out >> in;
        total -= out;
        if (total > maxnum) {
            maxnum = total;
        }
        total += in;
        if (total > maxnum) {
            maxnum = total;
        }
    }

    cout << maxnum;
}
