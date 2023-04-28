#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int K, temp, sum = 0;
    cin >> K;

    stack<int> s;
    for (int i = 0; i < K; i++) {
        cin >> temp;
        if (temp != 0) {
            s.push(temp);
        }
        else {
            s.pop();
        }
    }

    if (s.empty()) {
        cout << 0;
    }
    else {
        while (!s.empty()) {
            sum += s.top();
            s.pop();
        }
        cout << sum;
    }
    
}
