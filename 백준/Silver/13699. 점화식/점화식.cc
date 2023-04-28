#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;

    long long t[36];
    t[0] = 1;
    t[1] = 1;
    for (int i = 2; i <= n; i++) {
        long long sum = 0;
        for (int j = 0; j <= i - 1; j++) {
            sum += t[j] * t[i - j - 1];
        }
        t[i] = sum;
    }
    cout << t[n];
}