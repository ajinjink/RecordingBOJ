#include <iostream>
#include <algorithm>
#include <queue>
#define endl '\n'
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    queue<int> q, drop;
    for (int i  = 1; i <= N; i++) q.push(i);

    while (q.size() > 1) {
        int top = q.front();
        drop.push(top);
        q.pop();

        int next = q.front();
        q.pop();
        q.push(next);
    }

    while (!drop.empty()) {
        cout << drop.front() << ' ';
        drop.pop();
    }
    cout << q.front();

}
