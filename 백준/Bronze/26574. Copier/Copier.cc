#include <iostream>
using namespace std;

int main() {
    int n, temp;
    
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> temp;
        cout << temp << ' ' << temp << '\n';
    }
}