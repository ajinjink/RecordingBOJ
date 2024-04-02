#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
#define pii pair<int, int>
using ll = long long;
using namespace std;

string text, pattern;
int pi[1000001] = {0};
int res = 0;

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

void kmp() {
    int i = 0;
    for (int j = 0; j < text.length() - 1; j++) {
        while (i > 0 && pattern[i] != text[j]) {
            i = pi[i - 1];
        }
        if (pattern[i] == text[j]) {
            i++;
            if (i == pattern.length()) {
                res++;
                i = pi[i - 1];
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> text >> pattern;
    text = text + text;

    make_pi();
    kmp();

    cout << res;

}