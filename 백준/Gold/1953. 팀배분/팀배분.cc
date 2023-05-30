
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int visited[101] = {0};
vector<vector<int> > v;
queue<int> q;
vector<int> blue;
vector<int> white;
int start = 2;

void bfs(int node) {
    q.push(node);
    if (start == 1) {
        visited[node] = 1;
        start = 2;
        blue.push_back(node);
    }
    else {
        visited[node] = 2;
        start = 1;
        white.push_back(node);
    }
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        for (int i = 0; i < v[current].size(); i++) {
            int next = v[current][i];
  
            if (visited[current] == 1 && !visited[next]) {
                visited[next] = 2;
                white.push_back(next);
                q.push(next);
            }
            if (visited[current] == 2 && !visited[next]) {
                visited[next] = 1;
                blue.push_back(next);
                q.push(next);
            }
        }    
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, a, b;
    cin >> n;
    
    v.resize(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> a;
        for (int j = 0; j < a; j++) {
            cin >> b;
            v[i].push_back(b);
            v[b].push_back(i);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            bfs(i);
        }
    }
   


    sort(blue.begin(), blue.end());
    sort(white.begin(), white.end());
    
    cout << blue.size() << '\n';
    for (int i = 0; i < blue.size(); i++) {
        cout << blue[i] << ' ';
    }
    cout << '\n';
    cout << white.size() << '\n';
    for (int i = 0; i < white.size(); i++) {
        cout << white[i] << ' ';
    }
    
    
}
