#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
#define pii pair<int, int>
using ll = long long;
using namespace std;

string text, pattern;
int table[1000001] = {0};
vector<int> res;

void make_pi() {
    int i = 0;
    for (int j = 1; j < pattern.length(); j++) {
        while (i > 0 && pattern[i] != pattern[j]) {
            i = table[i - 1];
        }
        if (pattern[i] == pattern[j]) {
            i++;
            table[j] = i;
        }
    }
}

void kmp() {
    int i = 0;
    for (int j = 0; j < text.length(); j++) {
        while (i > 0 && pattern[i] != text[j]) i = table[i - 1];

        if (pattern[i] == text[j]) {
            i++;
            if (i == pattern.length()) {
                res.push_back(j - i + 1);
                i = table[i - 1];
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    getline(cin, text);
    getline(cin, pattern);

    make_pi();
    kmp();

    cout << res.size() << endl;
    for (int i = 0; i < res.size(); i++) cout << res[i] + 1 << ' ';
}