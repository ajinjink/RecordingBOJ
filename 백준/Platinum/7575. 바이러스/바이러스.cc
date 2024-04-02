#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
#define pii pair<int, int>
#define rng(a, b) for (int i = a; i < b; i++)
using ll = long long;
using namespace std;

int pi[1000001] = {0};
vector<vector<int>> v;

void make_pi(vector<int> pattern) {
    int i = 0;
    for (int j = 1; j < pattern.size(); j++) {
        while (i > 0 && pattern[i] != pattern[j]) {
            i = pi[i - 1];
        }
        if (pattern[i] == pattern[j]) {
            i++;
            pi[j] = i;
        }
    }
}

bool kmp(vector<int> text, vector<int> sub) {
    int i = 0;
    for (int j = 0; j < text.size(); j++) {
        while (i > 0 && sub[i] != text[j]) {
            i = pi[i - 1];
        }
        if (sub[i] == text[j]) {
            i++;
            if (i == sub.size()) {
                return true;
                i = pi[i - 1];
            }
        }
    }

    return false;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, K;
    cin >> N >> K;
    v.resize(N);

    for (int i = 0; i < N; i++) {
        int l;
        cin >> l;
        v[i].resize(l);
        for (int j = 0; j < l; j++) cin >> v[i][j];
    }
 
    bool res = false;
    for (int i = K - 1; i < v[0].size(); i++) {
        vector<int> sub;
        for (int j = i - K + 1; j <= i; j++) sub.push_back(v[0][j]);

        fill(pi, pi + 1000000, 0);
        make_pi(sub);

        bool temp = true;
        for (int j = 1; j < N; j++) {
            vector<int> rev = v[j];
            reverse(rev.begin(), rev.end());
            if (!kmp(v[j], sub) && !kmp(rev, sub)) {
                temp = false;
                break;
            }
        }
        if (temp) {
            res = true;
            break;
        }
    }
    
    if (res) cout << "YES";
    else cout << "NO";
    

}