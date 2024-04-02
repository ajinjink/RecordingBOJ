#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
#define pii pair<int, int>
using ll = long long;
using namespace std;

string text, pattern, alpha; // S, W, A
vector<int> pi;
vector<int> res;

void make_pi(string str) {
    int i = 0;
    for (int j = 1; j < str.length(); j++) {
        while (i > 0 && str[i] != str[j]) {
            i = pi[i - 1];
        }
        if (str[i] == str[j]) {
            i++;
            pi[j] = i;
        }
    }
}

vector<int> kmp() {
    make_pi(pattern);
    vector<int> cnt;
    int i = 0;
    for (int j = 0; j < text.length(); j++) {
        while (i > 0 && pattern[i] != text[j]) {
            i = pi[i - 1];
        }
        if (pattern[i] == text[j]) {
            i++;
            if (i == pattern.length()) {
                cnt.push_back(j - i + 1);
                i = pi[i - 1];
            }
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T;
    cin >> T;

    while (T--) {
        res.clear();
        pi.clear();
        cin >> alpha >> pattern >> text;
        pi.resize(pattern.length() + 2);

        for (int i = 0; i < alpha.length(); i++) { // shift
            vector<int> cnt = kmp();
            if (cnt.size() == 1) res.push_back(i);
            for (int j = 0; j < pattern.length(); j++) {
                for (int k = 0; k < alpha.length(); k++) {
                    if (pattern[j] == alpha[k]) {
                        pattern[j] = alpha[(k + 1) % alpha.length()];
                        break;
                    }
                }
            }
        }

        if (res.size() == 0) cout << "no solution";
        else if (res.size() == 1) {
            cout << "unique: ";
            for (int i = 0; i < res.size(); i++) cout << res[i] << ' ';
        }
        else {
            cout << "ambiguous: ";
            for (int i = 0; i < res.size(); i++) cout << res[i] << ' ';
        }
        cout << endl;
 
    }
}