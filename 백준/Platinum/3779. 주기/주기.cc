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
    
    int N, T = 1;
    cin >> N;

    while (N) {
        cin >> pattern;
        fill(&pi[0], &pi[pattern.length() + 1], 0);
        make_pi();

        cout << "Test case #" << T << endl;
        for (int i = 1; i < pattern.length(); i++) {
            if (pi[i] && (i + 1) % (i + 1 - pi[i]) == 0)
                cout << i + 1 << ' ' << (i + 1) / (i + 1 - pi[i]) << endl;
        }
        cout << endl;

        cin >> N;
        T++;
    }

}