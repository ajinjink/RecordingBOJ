#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
#define pii pair<int, int>
using ll = long long;
using namespace std;

string pattern;
int pi[1000001] = {0};

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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    
    cin >> pattern >> N;

    make_pi();

    ll res = pattern.length() + (N - 1)*(pattern.length() - pi[pattern.length() - 1]);
    cout << res;
}