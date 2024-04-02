#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int N;
int map[100001];
int visited[100001] = {0};
bool done[100001] = {0};
int cnt = 0;

void dfs(int n) {
    visited[n] = 1; // 1일 때는 사이클 찾는 중
    
    int next = map[n];

    if (!visited[next]) dfs(next);
    else if (!done[next]) { // 방문은 했는데 아직 사이클이 아님
        for (int i = next; i != n; i = map[i]) {
            cnt++;
        }
        cnt++;
    }
    done[n] = true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        cin >> N;
        for (int i = 1; i <= N; i++) {
            cin >> map[i];
        }
        for (int i = 1; i <= N; i++) {
            if (!visited[i]) dfs(i);
        }

        cout << N - cnt << '\n';
        cnt = 0;
        memset(visited, 0, sizeof(visited));
        memset(done, false, sizeof(done));
    }

}