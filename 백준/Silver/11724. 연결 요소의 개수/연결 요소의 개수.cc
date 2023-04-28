#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool visited[1001] = {0};
vector<int> graph[1001];

void dfs(int x) {
    visited[x] = true;
    for (int i = 0; i < graph[x].size(); i++) {
        int y = graph[x][i];
        if (!visited[y]) {
            dfs(y);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, res = 0; 
    cin >> N >> M;


    int c1, c2;
    for (int i = 0; i < M; i++) {
        cin >> c1 >> c2;
        graph[c1].push_back(c2);
        graph[c2].push_back(c1);
    }
    
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            dfs(i);
            res++;
        }
    }

    cout << res;
    

}