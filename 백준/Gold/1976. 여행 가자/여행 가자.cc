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

    int N, M, node, first;
    cin >> N >> M;
    parent.resize(N + 1);

     for (int i = 0; i <= N; i++) { // 대표 노드를 자기 자신으로 초기화
        parent[i] = i;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> node;
            if (node) {
                unionfunc(i, j);
            }
        }
    }

    for (int i = 0; i < M; i++) {
        cin >> node;
        if (i == 0) {
            first = node;
        }
        else {
            if (!checkSet(first, node)) {
                cout << "NO";
                return 0;
            };
        }

    }
    cout << "YES";



}