#include <iostream>
#include <vector>
using namespace std;

vector<int> v[2001];
int visited[2001] = {0};
bool flag = false;
// int link = 1;

void dfs(int n) {
    if (flag == true) {
        return;
    }
    if (visited[n] >= 5) {
        flag = true;
        return;
    }
    for (int i = 0; i < v[n].size(); i++) {
        if (visited[v[n][i]] == 0) {
            visited[v[n][i]] = visited[n] + 1;
            dfs(v[n][i]);
        }
    }
    visited[n] = 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, a, b;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for (int i = 0; i < N; i++) {
        if (visited[i] == 0 && v[i].size()) {
      
            visited[i] = 1;
            dfs(i);
        }
    }

   
    if (flag == false) {
        cout << 0;

    }
    else {
        cout << 1;
    }

}