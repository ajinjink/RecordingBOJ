#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#define endl '\n'
#define pii pair<int, int>
using ll = long long;
using namespace std;

int N, n1, n2;
vector<vector<int>> v; // 아래에서 위로 올라가는 단방향
vector<int> parent1, parent2, temp;

void init() {
    v.clear();
    v.resize(N + 1);
    parent1.clear();
    parent2.clear();
}

void dfs(int n) {
    temp.push_back(n);
    for (auto next : v[n]) {
        dfs(next);
    }
}
   
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T;
    cin >> T;

    while (T--) {
        cin >> N;

        init();

        for (int i = 0; i < N - 1; i++) {
            int a, b;
            cin >> a >> b;
            v[b].push_back(a); // b의 부모는 a이다
        }

        cin >> n1 >> n2; // 둘의 공통 조상 찾아라

        dfs(n1);
        parent1 = temp;
        temp.clear();
        dfs(n2);
        parent2 = temp;
        temp.clear();

        set<int> set1;
        for (int i = 0; i < parent1.size(); i++) set1.insert(parent1[i]);

        for (int i = 0; i < parent2.size(); i++) {
            if (set1.find(parent2[i]) != set1.end()) {
                cout << parent2[i] << endl;
                break;
            }
        }

    }

}