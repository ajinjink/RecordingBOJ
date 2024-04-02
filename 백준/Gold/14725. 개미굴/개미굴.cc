#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#define endl '\n'
#define pii pair<int, int>
using ll = long long;
using namespace std;

struct Trie {
    map<string, Trie*> m;

    void insert(vector<string> &v, int idx) {
        if (idx == v.size()) return;

        if (m.find(v[idx]) == m.end()) { // map에 현재 string 없으면
            Trie* trie = new Trie; // 새로운 부분 트리
            m.insert({v[idx], trie}); // 맵에 부분 트리 추가
        }

        m[v[idx]]->insert(v, idx + 1); // 맵의 현재 단어에 다음 단어부터 엮어
    }

    void dfs(int d) {
        for (auto& i : m) {
            for (int j = 0; j < d; j++) cout << "--";
            cout << i.first << endl;
            i.second->dfs(d + 1);
            delete i.second;
        }
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;

    Trie* root = new Trie;

    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;

        vector<string> v(k);
        for (int j = 0; j < k; j++) cin >> v[j];
        root->insert(v, 0); // 현재 부분 트리 생성
    }

    root->dfs(0);
    delete root;
}