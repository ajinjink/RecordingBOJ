#include <iostream>
#include <string>
using namespace std;

int main() {
    int N;
    string num;
    int sum = 0;

    cin >> N;
    cin >> num;
    
    for (int i = 0; i < N; i++) {
        sum += (int)num[i] - 48;
    }

    cout << sum;

} 