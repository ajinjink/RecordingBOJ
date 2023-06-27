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

    int sum = 0, temp;

    for (int i = 0; i < 6; i++) {
        cin >> temp;
        sum += temp;
    }

    cout << sum * 5;

}