#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arr[26];
    for (int i = 0; i < 26; i++) {
        arr[i] = -1;
    }

    string word;
    cin >> word;

    for (int i = 0; i < word.length(); i++) {
        if (arr[word[i] - 'a'] == -1) {
            arr[word[i] - 'a'] = i;
        }
    }

    for (int i = 0; i < 26; i++) {

        cout << arr[i] << ' ';
        
    }
    
}
