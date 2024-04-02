#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
#define pii pair<int, int>
using ll = long long;
using namespace std;

string pattern, text;
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

void kmp() {
    int i = 0;
    for (int j = 0; j < text.length() - 1; j++) {
        while (i > 0 && pattern[i] != text[j]) i = pi[i - 1];

        if (pattern[i] == text[j]) {
            i++;
            if (i == pattern.length()) {
                res.push_back(j - i + 1);
                i = pi[i - 1];
            }
        }
    }
}

int GCD(int a, int b) {
    if (b == 0) {
        return a;
    }
    else {
        return GCD(b, a % b);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;
    cin.ignore();
    getline(cin, text);
    text.erase(std::remove(text.begin(), text.end(), ' '), text.end());
    text = text + text;
    getline(cin, pattern);
    pattern.erase(std::remove(pattern.begin(), pattern.end(), ' '), pattern.end());

    make_pi();
    kmp();

    int num = res.size();
    int denum = N;
    int gcd = GCD(num, denum);
    num /= gcd;
    denum /= gcd;

    if (num >= denum) cout << "1/1";
    else cout << num << '/' << denum;

}