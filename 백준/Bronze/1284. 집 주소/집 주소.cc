#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string num;
    cin >> num;

    while (num[0] != '0') {
        int sum = 0;
        for (int i = 0; i < num.length(); i++) {
            if (num[i] == '1') {
                sum += 2;
            }
            else if (num[i] == '0') {
                sum += 4;
            }
            else {
                sum += 3;
            }
            
        }
        sum += (num.length() + 1);
        cout << sum << '\n';
        cin >> num;
    }
}