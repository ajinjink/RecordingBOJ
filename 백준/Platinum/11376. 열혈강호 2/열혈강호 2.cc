#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
vector<int> g[2010]; // 직원 그래프
vector<int> par(2010, -1);   // 일 그래프
bool visited[2010]; // 일 그래프 visited

int match(int v) { // v번 직원을 다른 일과 매칭할 수 있는가?
    for (auto n : g[v]) { // v와 연결된 저쪽 그래프 노드들
        if (visited[n]) continue;
        visited[n] = 1;
        if (par[n] == -1 || match(par[n])) { // 매칭 안 됐거나 다른 점과 매칭 가능
            par[n] = v; // 연결
            return 1;
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        int n;
        cin >> n;

        for (int j = 0; j < n; j++) {
            int a;
            cin >> a;
            g[i].push_back(a);
            g[1000 + i].push_back(a);
        }
    }

    int res = 0;
    for (int i = 1; i <= N; i++) {
        fill(&visited[0], &visited[1011], 0);
        if (match(i)) res++;
        fill(&visited[0], &visited[1011], 0);
        if (match(1000 + i)) res++;
    }


    cout << res;
}