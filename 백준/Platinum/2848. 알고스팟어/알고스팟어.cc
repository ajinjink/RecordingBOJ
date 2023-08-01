#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<string> words(N);
    vector<vector<int> > v(26);
    bool visited[26] = {0};
    int indegree[26] = {0};
    int alphacount = 0;

    for (int i = 0; i < N; i++) {
        cin >> words[i];

        for (char c : words[i]) {
            if (!visited[c - 'a']) {
                visited[c - 'a'] = true;
                alphacount++;
            } 
        }
    }


    for (int i = 0; i < N - 1; i++) {
        bool sub = true;
        for (int j = 0; j < min(words[i].length(), words[i + 1].length()); j++) {

            if (words[i][j] != words[i + 1][j]) {
                v[words[i][j] - 'a'].push_back(words[i + 1][j] - 'a');
                indegree[words[i + 1][j] - 'a']++;
                sub = false;
                break;
            }

        }
        if (sub) {

            if (words[i + 1].size() < words[i].size()) { // 입력이 사전 순이 아니다?
                cout << '!';
                return 0;
            }
        }
    }

    queue<int> q;
    for (int i = 0; i < 26; i++) {
        if (visited[i] && !indegree[i]) {
            q.push(i);
        }
    }

    vector<int> res;
    bool multiple = false;

    while (!q.empty()) {
        if (q.size() > 1) {
            multiple = true;
        }

        int now = q.front();
        q.pop();

        res.push_back(now);

        for (int next : v[now]) {
            if (visited[next] && !(--indegree[next])) q.push(next);
        }
    }

    if (res.size() != alphacount) {
        cout << '!';
        return 0;
    }
    else if (multiple) {
        cout << '?';
        return 0;
    }
    
    for (int i = 0; i < res.size(); i++) {
        cout << (char)(res[i] + 'a');
    }

    
}




