#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M;
    string cmd;
    int num;

    vector<int> v;

    cin >> M;
    
    for (int i = 0; i < M; i++) {
        cin >> cmd;
        if (cmd == "add") {
            cin >> num;
            if (!binary_search(v.begin(), v.end(), num)) {
                v.push_back(num);
            }
        }
        if (cmd == "remove") {
            cin >> num;
            if (binary_search(v.begin(), v.end(), num)) {
                v.erase(remove(v.begin(), v.end(), num), v.end());
            }
        }
        if (cmd == "check") {
            cin >> num;
            if (binary_search(v.begin(), v.end(), num)) {
                cout << 1 << '\n';
            }
            else {
                cout << 0 << '\n';
            }
        }
        if (cmd == "toggle") {
            cin >> num;
            if (binary_search(v.begin(), v.end(), num)) {
                v.erase(remove(v.begin(), v.end(), num), v.end());
            }
            else {
                v.push_back(num);
            }
        }
        if (cmd == "all") {
            v.clear();
            for (int i = 1; i <= 20; i++) {
                v.push_back(i);
            }
        }
        if (cmd == "empty") {
            v.clear();
        }
    }
    sort(v.begin(), v.end());
}