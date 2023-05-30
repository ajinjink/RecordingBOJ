#include <iostream>
#include <algorithm>
using namespace std;

int64_t isPalindrome(string str) {
    
    for (int i = 0; i < str.length() / 2; i++) {
        if (str[i] != str[str.length() - 1 - i]) {
            return 0;
        }
    }
    return 1;

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string word;
    cin >> word;
    cout << isPalindrome(word);

}