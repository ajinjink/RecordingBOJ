#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    cin >> str;

    int arr[26] = {0};

    for (int i = 0; i < str.length(); i++) {
        arr[str[i] - 97]++;
    }

    for (int i = 0; i < 26; i++) {
        cout << arr[i] << ' ';
    }
}