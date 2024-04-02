#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

typedef struct Edge {
    int s, e, v;
    bool operator > (const Edge& temp) const {
        return v > temp.v;
    }
} Edge;

static vector<int> parent;

int find(int a) {
    if (a == parent[a]) return a;
    else return parent[a] = find(parent[a]);
}

void munion(int a, int b) {
    a = find(a);
    b = find(b);

    if (a != b) parent[b] = a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int V, E;
    cin >> V >> E;

    parent.resize(V + 1);
    for (int i = 0; i <= V; i++) parent[i] = i;

    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
    for (int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        pq.push(Edge{a, b, c});
    }

    int edgenum = 0, res = 0;
    while (edgenum < V - 1) {
        Edge now = pq.top();
        pq.pop();
        if (find(now.s) != find(now.e)) { // 같은 부모 아니면 (사이클 아니면)
            munion(now.s, now.e);
            res += now.v;
            edgenum++;
        }
    }

    cout << res;
}