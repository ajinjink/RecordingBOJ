#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

vector<vector<pair<int, int> > > v;
int visited[100001] = {0};

void dfs(int n) {
    for (int i = 0; i < v[n].size(); i++) {
        if (visited[v[n][i].first] == 0) {
            visited[v[n][i].first] = visited[n] + v[n][i].second;
            dfs(v[n][i].first);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int V;
    cin >> V;
    v.resize(V + 1);
    for (int i = 0; i < V - 1; i++) {
        int parent, child, dist;
        cin >> parent >> child >> dist;
        v[parent].push_back(make_pair(child, dist));
        v[child].push_back(make_pair(parent, dist));

    }

   
  
    visited[1] = 1;
    dfs(1);
    int maxNode = 0;
    for (int i = 1; i <= V; i++) {
        if (visited[i] > visited[maxNode]) {
            maxNode = i;
        }
    }
    memset(visited, 0, sizeof(visited));
    visited[maxNode] = 1;
    dfs(maxNode);
    sort(visited, visited + V + 1);
    cout << visited[V] - 1;



}