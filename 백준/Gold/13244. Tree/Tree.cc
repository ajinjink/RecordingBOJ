#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
using namespace std;

int N, M;
vector<int> parent;

int find(int a) {
    if (parent[a] == a) return a;
    else return parent[a] = find(parent[a]);
}

bool unite(int a, int b) {
    a = find(a);
    b = find(b);

    if (a == b) return false;
    else {
        parent[b] = a;
        return true;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        cin >> N;
        parent.clear();
        parent.resize(N + 1);
        for (int i = 0; i <= N; i++) parent[i] = i;

        cin >> M;
        bool graph = false;
        for (int i = 0; i < M; i++) {
            int a, b;
            cin >> a >> b;
            if (!unite(a, b)) {
                graph = true;
                // break;
            }
        }

        if (!graph) {
            int prev = find(1); // 그래프가 하나로 연결되어 있지 않으면
            for (int i = 1; i <= N; i++) {
                if (find(i) != prev) graph = true; // 서로 다른 집합이면 트리 아님. 그래프.
            }
        }

        if (M != N - 1) graph = true;

        if (graph) cout << "graph" << endl;
        else cout << "tree" << endl;
    }
}
