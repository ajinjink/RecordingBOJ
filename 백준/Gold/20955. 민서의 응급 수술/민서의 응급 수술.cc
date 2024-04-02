#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
#define pii pair<int, int>
using ll = long long;
using namespace std;

int N, M;
vector<int> parent;
int res = 0;

int find(int a) {
    if (parent[a] == a) return a;

    return parent[a] = find(parent[a]);
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);

    if (a != b) parent[b] = a;
}

bool check(int a, int b) {
    a = find(a);
    b = find(b);
    
    if (a == b) return true;
    else return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    
    parent.resize(N + 1);
    for (int i = 0; i <= N; i++) parent[i] = i;

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;

        if (check(a, b)) { // 이미 같은 그룹. 여기서 이어버리면 사이클
            res++; // 이 뉴런 끊어
        }
        else unite(a, b);
    }

    int prev = parent[1];
    for (int i = 2; i <= N; i++) {
        if (!check(prev, parent[i])) {
            unite(prev, parent[i]);
            res++;
        }
        prev = parent[i];
    }

    cout << res;

}