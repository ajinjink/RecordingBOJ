#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
#define pii pair<int, int>
#define rng(a, b) for (int i = a; i < b; i++)
using ll = long long;
using namespace std;

string pattern;
int pi[1000001] = {0};
vector<string> sub;

void make_pi() {
    int i = 0;
    for (int j = 1; j < pattern.length(); j++) {
        while (i > 0 && pattern[i] != pattern[j]) {
            i = pi[i - 1];
        }
        if (pattern[i] == pattern[j]) {
            i++;
            pi[j] = i;
        }
    }
}

bool kmp(string sub) {
    int i = 0;
    for (int j = 0; j < pattern.length(); j++) {
        while (i > 0 && sub[i] != pattern[j]) {
            i = pi[i - 1];
        }
        if (sub[i] == pattern[j]) {
            i++;
            if (i == sub.length()) {
                if (j != sub.length() - 1 && j != pattern.length() - 1) return true;
                i = pi[i - 1];
            }
        }
    }

    return false;
}

bool compare(string a, string b) {
    if (a.length() == b.length()) return a < b;
    return a.length() > b.length();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> pattern;
    make_pi();

    for (int i = pi[pattern.length() - 1]; i > 0; i--) {
        if (pattern.substr(0, i) == pattern.substr(pattern.length() - i, pattern.length() - 1)) {
            if (kmp(pattern.substr(0, i))) {
                cout << pattern.substr(0, i);
                return 0;
            }
        }
    }

    cout << -1;

}