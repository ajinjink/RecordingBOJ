#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<int> arr(N, 0);
    vector<int> res(N, 0);

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    stack<int> s;
    s.push(0);

    for (int i = 0; i < N; i++) {
        while (!s.empty() && arr[s.top()] < arr[i]) {
            res[s.top()] = arr[i];
            s.pop();
        }
        s.push(i);
    }

    while (!s.empty()) {
        res[s.top()] = -1;
        s.pop();
    }

    for (int i = 0; i < N; i++) {
        cout << res[i] << ' ';
    }
}

