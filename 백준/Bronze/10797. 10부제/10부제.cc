#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int first;
    cin >> first;

    int num;
    int res = 0;
    for (int i = 0; i < 5; i++) {
        cin >> num;
        if (num == first) {
            res++;
        }
    }

    cout << res;

    

}