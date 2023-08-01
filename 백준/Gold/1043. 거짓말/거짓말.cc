// union find

#include <iostream>
#include <vector>
using namespace std;

vector<int> parent;
vector<int> trueP;
vector<vector<int> > party;
int res;

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

    int N, M, T;
    cin >> N >> M >> T;
    trueP.resize(T);

    for (int i = 0; i < T; i++) {
        cin >> trueP[i];
    }

    party.resize(M);
    for (int i = 0; i < M; i++) {
        int party_size;
        cin >> party_size;

        for (int j = 0; j < party_size; j++) {
            int temp;
            cin >> temp;
            party[i].push_back(temp);
        }
    }

    parent.resize(N + 1);

    for (int i = 0; i <= N; i++){
        parent[i] = i;
    }

    for (int i = 0; i < M; i++) {
        int firstPeople = party[i][0];
        for (int j = 1; j < party[i].size(); j++) {
            unionfunc(firstPeople, party[i][j]);
        }
    }

    for (int i = 0; i < M; i++) {
        bool isPossible = true;
        int cur = party[i][0];

        for (int j = 0; j < T; j++) {
            if (find(cur) == find(trueP[j])) {
                isPossible = false;
                break;
            }
        }
        if (isPossible) {
            res++;
        }
    }

    cout << res;
}