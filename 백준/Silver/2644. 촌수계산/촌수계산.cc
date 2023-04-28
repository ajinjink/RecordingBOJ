#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

vector<int> v[101];
int visited[101] = {0};
int n, m, A, B, found = 0;
queue<int> q;

void bfs(int A) {
    q.push(A);
    visited[A] = 1;
    while (!q.empty()) {
        int now = q.front();
        
        q.pop();
        
        for (int i = 0; i < v[now].size(); i++) {
            if (v[now][i] == B) {
                cout << visited[now];
                found = 1;
                return;
            }
            else {
                if (!visited[v[now][i]]) {
                    q.push(v[now][i]);   
                    visited[v[now][i]] = visited[now] + 1;
                    
                }
            }

        }
    }
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int x, y;
    cin >> n >> A >> B >> m;

    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    bfs(A);

    if (found == 0) {
        cout << -1;
        return 0 ;
    }
    

}


