#include <iostream>
#include <vector>
using namespace std;

bool visited[101];
vector<int> graph[101];

int countv = 0;

void dfs(int x) {
    visited[x] = true;
    countv++;
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

    int N, M; 
    cin >> N; 
    cin >> M;

    int c1, c2;
    for (int i = 0; i < M; i++) {
        cin >> c1 >> c2;
        graph[c1].push_back(c2);
        graph[c2].push_back(c1);
    }

    dfs(1);
    cout << countv - 1;

}