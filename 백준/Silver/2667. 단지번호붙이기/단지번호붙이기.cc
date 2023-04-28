#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N;
vector<int> v; 
queue<pair<int, int> > q;
string map[26];
int visited[26][26] = {0,};
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int cnt = 0;

void bfs(int r, int c) {
    q.push(make_pair(r, c));

    visited[r][c] = 1;
    cnt++;
    
    while (!q.empty()) {
        int a = q.front().first; // r
        int b = q.front().second; // c
        q.pop();

        visited[a][b] = 1;

        for (int i = 0; i < 4; i++) {
            if (0 <= a + dx[i] && a + dx[i] < N && 0 <= b + dy[i] && b + dy[i] < N) {
                if (map[a + dx[i]][b + dy[i]] == '1' && visited[a + dx[i]][b + dy[i]] == 0) {
                    q.push(make_pair(a + dx[i], b + dy[i]));
                    visited[a + dx[i]][b + dy[i]] = 1;
                    cnt++;
                }            
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> map[i];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] == '1' && visited[i][j] == 0) {
                cnt = 0;
                bfs(i, j);
                v.push_back(cnt);
            }
        }
    }

    sort(v.begin(), v.end());
    
    cout << v.size() << '\n';
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << '\n';
        
    }
    
}