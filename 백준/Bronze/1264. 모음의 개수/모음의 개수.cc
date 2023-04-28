#include <iostream>
using namespace std;

int main() {
    
    char str[260];
    cin.getline(str, 260);

    int vowels[5] = {97, 101, 105, 111, 117};
    
    while (str[0] != '#') {
        int count = 0;
        int i = 0;
        while (str[i]) {
            for (int j = 0; j < 5; j++) {
                if (str[i] == vowels[j] || str[i] == vowels[j] - 32) {
                    count++;
                }
            }
            i++;
        }
        cout << count << '\n';
        cin.getline(str, 260);
    }
}