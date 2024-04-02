#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
#define endl '\n'

static vector<int> v;

void divide(int index, int size) {
    if (size == 1) return;

    divide(index, size / 3);
    divide(index + (size / 3), size / 3);
    divide(index + (size * 2 / 3), size / 3);

    for (int i = index + (size /  3); i < index + + (size * 2 /  3); i++) v[i] = 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    
    while (cin >> N) {
        v.clear();
        v.resize(pow(3, N), 1);

        divide(0, pow(3, N));

        for (int i = 0; i < v.size(); i++) {
            if (v[i] == 1) cout << '-';
            else cout << ' ';
        }
        cout << endl;
    }
    
}