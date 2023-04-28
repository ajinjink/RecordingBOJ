#include <iostream>
#include <stack>
using namespace std;

int main() {
    int N;
    cin >> N;
    string command;
    int num;
    stack<int> s;
    for (int i = 0; i < N; i++) {
        cin >> command;
        if (command == "push") {
            cin >> num;
            s.push(num);
        }
        if (command == "pop") {
            if (!s.empty()) {
                cout << s.top()<< '\n';
                s.pop();
            }
            else {
                cout << -1 << '\n';
            }
            
        }
        if (command == "size") {
            cout << s.size() << '\n';
        }
        if (command == "empty") {
            cout << s.empty() << '\n';
        }
        if (command == "top") {
            if (!s.empty()) {
                cout << s.top() << '\n';
            }
            else {
                cout << -1 << '\n';
            }
        }

    }
}
