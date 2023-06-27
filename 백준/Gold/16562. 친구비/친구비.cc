// union find

#include <iostream>
#include <vector>
using namespace std;

vector<int> parent;
vector<int> friendfee;
int visited[10001] = {0};

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
        if (friendfee[a] > friendfee[b]) {
            parent[a] = b;
        }
        else {
            parent[b] = a; // b의 대표 노드를 a로 갱신
        }    
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, k, v, w;
    cin >> N >> M >> k;
    parent.resize(N + 1);
    friendfee.resize(N + 1);

    for (int i = 0; i <= N; i++) {
        parent[i] = i;
    }

    for (int i = 1; i <= N; i++) {
        cin >> friendfee[i];
    }

    for (int i = 0; i < M; i++) {
        cin >> v >> w;
        unionfunc(v, w);
    }

    int res = 0, cur;
    for (int i = 1; i <= N; i++) {
        int curp = find(i);
        if (!visited[curp]) {
            res += friendfee[curp];
            visited[curp] = 1;
        }
	}



    if (res <= k) {
        cout << res;
    }
    else {
        cout << "Oh no";
    }
}