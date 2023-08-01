// union find

#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
using namespace std;

int parent[200001];
map<string, int> m;
int friendnum[200001];

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

        friendnum[a] += friendnum[b];
        friendnum[b] = friendnum[a];
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

    int t, f, p1, p2;
    string a, b;
    cin >> t;

    while (t--) {
        m.clear();

        cin >> f;

        int cnt = 0;

        for (int i = 0; i < 200001; i++) {
            parent[i] = i;
            friendnum[i] = 1;
        }
        
        for (int i = 0; i < f; i++) {
            

            cin >> a >> b;
            
            if (m.count(a) == 0) {
                m[a] = cnt++;
            }
            if (m.count(b) == 0) {
                m[b] = cnt++;
            }

            unionfunc(m[a], m[b]);

            p1 = find(m[a]);
            p2 = find(m[b]);

            cout << max(friendnum[p1], friendnum[p2]) << '\n';

        }

    }

}


