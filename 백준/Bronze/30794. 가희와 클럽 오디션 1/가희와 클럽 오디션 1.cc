#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
#define pii pair<int, int>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int cnt; string lvl;
    cin >> cnt >> lvl;

    if (lvl == "miss") cout << 0;
    else if (lvl == "bad") cout << 200 * cnt;
    else if (lvl == "cool") cout << 400 * cnt;
    else if (lvl == "great") cout << 600 * cnt;
    else if (lvl == "perfect") cout << 1000 * cnt;


}