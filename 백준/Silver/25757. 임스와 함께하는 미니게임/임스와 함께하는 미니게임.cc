#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#define endl '\n'
#define pii pair<int, int>
using ll = long long;
using namespace std;

set<string> s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    char game;
    cin >> N >> game;

    for (int i = 0; i < N; i++) {
        string name;
        cin >> name;
        s.insert(name);
    }

    if (game == 'Y') cout << s.size();
    else if (game == 'F') cout << s.size() / 2;
    else cout << s.size() / 3;
}