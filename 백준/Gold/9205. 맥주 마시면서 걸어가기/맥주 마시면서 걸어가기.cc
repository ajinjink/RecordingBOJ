#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>
using namespace std;

vector<pair<int, int> > arr;
vector<int> v[105];
queue<int> q;
int visited[105] = {0};
bool reached = false;
int n;

void bfs() {
    q.push(0);
    visited[0] = 1;

    while (!q.empty()) {
        int current = q.front();
        visited[current] = 1;
        q.pop();
        if (current == n + 1) {
            reached = true;
            return;
        }
        for (int i = 0; i < v[current].size(); i++) {
            if (visited[v[current][i]] == 0) {
                q.push(v[current][i]);
                visited[v[current][i]] = 1;
            }
            
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    for (int T = 0; T < t; T++) {

        int a, b, dist;
        cin >> n;
        
        for (int k = 0; k < n + 2; k++) {
            cin >> a >> b;
            arr.push_back(make_pair(a, b));
        }

        for (int i = 0; i < arr.size() - 1; i++) {
            for (int j = i + 1; j < arr.size(); j++) {
                dist = abs(arr[i].first - arr[j].first) + abs(arr[i].second - arr[j].second);
                if (dist <= 1000) {
                    v[i].push_back(j);
                    v[j].push_back(i);
                } 
                
            } 
        }

        bfs();

        if (reached) {
            cout << "happy" << '\n';
        }
        else {
            cout << "sad" << '\n';
        }

  
        arr.clear();
        for (int i = 0; i < n + 2; i++) {
            v[i].clear();
        }
        while (!q.empty()) {
            q.pop();
        }
        memset(visited, 0, sizeof(visited));
        reached = false;
        
        
        
    }
}

