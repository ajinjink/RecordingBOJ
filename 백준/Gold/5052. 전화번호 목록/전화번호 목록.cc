/*
트라이 (trie) 알고리즘
단어를 트리로 만들어서, 앞이 겹치는 단어는 쭉 노드 타고 내려가다가, 겹치지 않는 부분 발생하면 새로운 브랜치 생성
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#define endl '\n'
#define pii pair<int, int>
using ll = long long;
using namespace std;

bool interrupt;

class Node {
    public:
    Node* next[10];
    bool isEnd;
    Node() : isEnd(false) {
        fill(next, next + 10, nullptr);
    }

    ~Node() {
        for (auto& child : next) delete child;
    }

    void insert(const char* key) { // 문자열 삽입
        if (*key == 0) isEnd = true; // 다 넣었어
        else {
            int next_index = *key - '0';
            if (next[next_index] == nullptr) { 
                next[next_index] = new Node();
                interrupt = true; // 새로운 노드 만들었으면 interrupt true
            }
            next[next_index] -> insert(key + 1);
        }
    }
};

bool compare(string a, string b) {
    return a.length() > b.length();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n; 
        cin >> n;

        Node* root = new Node();
        vector<string> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        sort(v.begin(), v.end(), compare);

        bool res = true;
        
        for (int i = 0; i < n; i++) {
            char num[51];
            strcpy(num, v[i].c_str());
            interrupt = false;
            root->insert(num);
            if (i > 0 && !interrupt) { // 처음에는 당연히 다 새로 만들어. 2번째부터 새로운 노드 안 만들면 일관성 없음
                res = false; // new node 만들었으면 interrupt true. 일관성 있음
                break;
            }
            // if (root->interrupt) cout << "YES" << endl;
            // else cout << "NO" << endl;
        }

        if (res) cout << "YES" << endl;
        else cout << "NO" << endl;

        delete root;

    }
}