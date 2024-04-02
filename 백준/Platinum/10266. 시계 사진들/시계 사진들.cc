#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
#define pii pair<int, int>
#define rng(a, b) for (int i = a; i < b; i++)
using ll = long long;
using namespace std;

int pi[2000001] = {0};
vector<int> text(720000, 0);
vector<int> pattern(360000, 0);

void make_pi() {
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

bool kmp() {
    int i = 0;
    for (int j = 0; j < text.size(); j++) {
        while (i > 0 && pattern[i] != text[j]) {
            i = pi[i - 1];
        }
        if (pattern[i] == text[j]) {
            i++;
            if (i == pattern.size()) {
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
    
    int N, num;
    cin >> N;

    rng(0, N) {
        cin >> num;
        text[num + 360000] = text[num] = 1;
    }
    rng(0, N) {
        cin >> num;
        pattern[num] = 1;
    }

    make_pi();

    if (kmp()) cout << "possible";
    else cout << "impossible";

}