#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, temp;
    cin >> N;

    queue<int> q;
    string command;

    for (int i = 0; i < N; i++) {
        cin >> command;
        if (command == "push") {
            cin >> temp;
            q.push(temp);
        }
        if (command == "pop") {
            if (q.empty()) {
                cout << -1 << '\n';
            }
            else{
                cout << q.front() << '\n';
                q.pop();
            }
        }
        if (command == "size") {
            cout << q.size() << '\n';
        }
        if (command == "empty") {
            cout << q.empty() << '\n';
        }
        if (command == "front") {
            if (q.empty()) {
                cout << -1 << '\n';
            }
            else {
                cout << q.front() << '\n';
            }
        }
        if (command == "back") {
            if (q.empty()) {
                cout << -1 << '\n';
            }
            else {
                cout << q.back() << '\n';
            }
        }
    }
}