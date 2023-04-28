#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int chicken, cola, beer, drink;
    cin >> chicken >> cola >> beer;
    drink = (cola / 2) + beer;

    cout << min(chicken, drink);

}