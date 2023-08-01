#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	string str;
    cin >> str;

    stack<char> s;

    for (char c : str) {
        if ('A' <= c and c <= 'Z') cout << c;
        else {
            if (c == '(') s.push(c);
            else if (c == '+' or c == '-') {
                while (!s.empty() && s.top() != '(') {
                    char op = s.top();
                    cout << op;
                    s.pop();
                }
                s.push(c);
            }
            else if (c == '*' or c == '/') {
                while (!s.empty() && s.top() != '(' && (s.top() == '*' || s.top() == '/')) {
                    char op = s.top();
                    cout << op;
                    s.pop();
                }
                s.push(c);
            }
            else if (c == ')') {
                while (!s.empty() && s.top() != '(') {
                    char op = s.top();
                    cout << op;
                    s.pop();
                }
                s.pop(); // s.top() == '('
            }
        }
    }
    
    while (!s.empty()) {
        char op = s.top();
        cout << op;
        s.pop();
    }
    
}