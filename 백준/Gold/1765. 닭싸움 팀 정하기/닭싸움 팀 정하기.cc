#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int n, m;
vector<int> parent;
vector<vector<int>> v;

int find(int a) {
    if (parent[a] == a) return a;

    return parent[a] = find(parent[a]);
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);

    if (a != b) parent[b] = a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    parent.resize(n + 1);
    v.resize(n + 1);
    for (int i = 0; i <= n; i++) parent[i] = i;

    for (int i = 0; i < m; i++) {
        char c;
        int a, b;
        cin >> c >> a >> b;

        if (c == 'E') {
            v[a].push_back(b);
            v[b].push_back(a);
        }
        else {
            unite(a, b);
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j : v[i]) { // i의 적
            for (int k : v[j]) { // 적의 적
                unite(parent[i], parent[k]);
            }
        }
    }

    set<int> res;

    for (int i = 1; i <= n; i++) {
        res.insert(find(i));
    }

    cout << res.size();

}

