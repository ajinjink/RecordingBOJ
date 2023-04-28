
#include <iostream>
#include <stack>
using namespace std;

int main() {
    
    while (1) {
        stack<char> s;
        string str;
        string ans = "yes";

        getline(cin, str);
        if (str[0] == '.') {
            break;
        }

        for (int i = 0; i < str.length(); i++) {
            if ((str[i] == '(') || (str[i] == '[')) {

                s.push(str[i]);
            }
            else if (str[i] == ')'){
                if (!s.empty() && s.top() == '(') {
                    s.pop();
                }
                else {
                    ans = "no";
                    break;
                }
            }
            else if (str[i] == ']'){
                if (!s.empty() && s.top() == '[') {
                    s.pop();
                }
                else {
                    ans = "no";
                    break;
                }

            }

        }
        if (!s.empty()) {
            ans = "no";
        }
        cout << ans << '\n';
    }
}