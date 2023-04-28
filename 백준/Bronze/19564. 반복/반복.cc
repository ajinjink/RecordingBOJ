#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long res = 1;
    string S;
    cin >> S;
    char prev = S[0];
    char current;

    for (long long int i = 1; i < S.length(); i++) {
        current = S[i];
        if (current <= prev) {
            res++;
        }
        prev = current;        
    }

    cout << res;
}







