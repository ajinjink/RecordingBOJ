#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    long sum = 0;
    int num;
    
    for (int i = 0; i < 5; i++) {
        cin >> num;
        sum += (num * num);
    }

    cout << sum % 10;
}