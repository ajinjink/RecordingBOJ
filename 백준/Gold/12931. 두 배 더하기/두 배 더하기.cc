#include <iostream>
#include <queue>
using namespace std;

int main() {
    int N;
    cin >> N;

    queue<int> q;

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        if (num) q.push(num);
    }

    int cnt = 0;
    while (!q.empty()) {
        int loop = q.size();
        for (int i = 0; i < loop; i++) {
            int top = q.front();
            q.pop();
            if (top) {
                if (top % 2) {
                    top--;
                    cnt++;
                }
                if (top) q.push(top);
            }
        }

        loop = q.size();
        if (loop) cnt++;
        for (int i = 0; i < loop; i++) {
            int top = q.front();
            q.pop();
            top /= 2;
            q.push(top);
        }
        
    }

    cout << cnt;


}