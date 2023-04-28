#include <iostream>
#include <deque>
using namespace std;

int main() {
    int N, temp;
    cin >> N;
    deque<int> d;
    string command;

    for (int i = 0; i < N; i++) {
        cin >> command;

        if (command == "push_front") {
            cin >> temp;
            d.push_front(temp);
        }
        if (command == "push_back") {
            cin >> temp;
            d.push_back(temp);
        }
        if (command == "pop_front") {
            if (d.empty()) {
                cout << -1 << '\n';
            }
            else {
                cout << d.front() << '\n';
                d.pop_front();
            }

        }
        if (command == "pop_back") {
            if (d.empty()) {
                cout << -1 << '\n';
            }
            else {
                cout << d.back() << '\n';
                d.pop_back();
            }
        }
        if (command == "size") {
            cout << d.size() << '\n';

        }
        if (command == "empty") {
            cout << d.empty() << '\n';
        }
        if (command == "front") {
            if (d.empty()) {
                cout << -1 << '\n';
            }
            else {
                cout << d.front() << '\n';
            }
        }
        if (command == "back") {
            if (d.empty()) {
                cout << -1 << '\n';
            }
            else {
                cout << d.back() << '\n';
            }
        }

    }
}