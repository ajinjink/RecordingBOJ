#include <iostream>
#include <stack>
using namespace std;

int main() {
    int N;
    string str;
    cin >> N;

    stack<char> s;


    for (int i = 0; i < N; i++) {
        while (!s.empty()) {
            s.pop();
        }

        cin >> str;
        string asw = "YES";
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == '(') {

                s.push(str[i]);

            }
            else if (str[i] == ')'){
                if (s.empty()){
                    asw = "NO";
                    break;
                }
                else if (s.top() == '(') {
                    s.pop();

                }
            }
        }
        if (!s.empty()) asw = "NO";
        cout << asw << endl;
        
    }
}