#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    int n;
    while (cin >> n && n > 0) {
        vector<string> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        int top = 0, bottom = n/2 + n%2;
        for (int i = 0; i < n/2; i++) {
            cout << v[top++] << '\n';
            cout << v[bottom++] << '\n';
        }
        if (top < n/2 + n % 2) {
            cout << v[top++] << '\n';
        }
    }
}