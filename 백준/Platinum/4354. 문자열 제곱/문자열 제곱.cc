#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
#define pii pair<int, int>
using ll = long long;
using namespace std;

string pattern;
int pi[1000001] = {0};
vector<int> res;

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
    
    cin >> pattern;

    while (pattern != ".") {
        fill(&pi[0], &pi[pattern.length() + 1], 0);
        make_pi();

        int res;
        if (pi[pattern.length() - 1] && pattern.length() % (pattern.length() - pi[pattern.length() - 1]) == 0)
            res = pattern.length() / (pattern.length() - pi[pattern.length() - 1]);
        else res = 1;
        cout << res << endl;
        
        cin >> pattern;
    }

}