#include <iostream>
#include <vector>
using namespace std;

static int parent[100001] = {0}; // 그 값에 들어갈 수 있는 가장 높은 게이트
static int arr[100001] = {0};

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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int G, P;
    cin >> G >> P;

    for (int i = 0; i <= G; i++) parent[i] = i;

    for (int i = 0; i < P; i++) {
        cin >> arr[i];
        if (find(arr[i]) == 0) { // 대표 노드가 0이면
            break;
        }
        unionfunc(find(arr[i]) - 1, find(arr[i]));
    }

    int res = 0;
    for (int i = 1; i <= G; i++) {
        if (parent[i] != i) res++;
    }

    cout << res;
}


