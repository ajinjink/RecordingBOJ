// union find

#include <iostream>
#include <vector>
using namespace std;

vector<int> parent;

int find(int a) {
    if (a == parent[a]) { // 대표 노드를 찾으면 반환
        return a;
    }
    else { // 대표 노드에 도달할 때까지 거치는 모든 노드 값을 대표 노드값으로 변경
        return parent[a] = find(parent[a]);
    }
}

void unionfunc(int a, int b) {
    a = find(a); // a의 대표 노드 찾아
    b = find(b); // b의 대표 노드 찾아

    if (a != b) { // 다른 집합이라면
        parent[b] = a; // b의 대표 노드를 a로 갱신
    }
}

bool checkSet(int a, int b) { // 같은 집합인가
    a = find(a); // a의 대표 노드 찾아
    b = find(b); // b의 대표 노드 찾아

    if (a == b) {
        return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, a, b, res = 0;
    cin >> n >> m;

    parent.resize(n);
    for (int i = 0; i < n; i++) { // 대표 노드를 자기 자신으로 초기화
        parent[i] = i;
    }

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        if (!checkSet(a, b)) {
            unionfunc(a, b);
        }
        else {
            if (res == 0) {
                res = i + 1;
            }
        }
    }
    cout << res;

    return 0;
}