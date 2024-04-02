#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int F, S, G, U, D;
vector<int> visited;

int bfs() {
    queue<int> q;
    q.push(S);
    visited[S] = -1;

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        if (now == G) return 1;

        if (now + U <= F && !visited[now + U]) {
            q.push(now + U);
            visited[now + U] = now;
        }
        if (now - D > 0 && !visited[now - D]) {
            q.push(now - D);
            visited[now - D] = now;
        }
    }

    return 0;
}

int main() {
    cin >> F >> S >> G >> U >> D; // 총 F층, 지금 S, G로 가고 싶어

    visited.resize(F + 1, 0);

    int cnt = 0;
    if (bfs()) {
        int now = G;
        while (now != -1) {
            int parent = visited[now];
            cnt++;
            now = parent;
            // cout << now << endl;
        }
        cout << cnt - 1;
    }
    else {
        cout << "use the stairs";
    }


}