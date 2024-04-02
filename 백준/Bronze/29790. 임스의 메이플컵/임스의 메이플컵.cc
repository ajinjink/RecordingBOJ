#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <cstring>
#include <sstream>
#include <limits.h>
#define endl '\n'
#define pii pair<int, int>
#define tiiii tuple<int, int, int, int>
using ll = long long;
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, U, L;
    cin >> N >> U >> L;

    if (N >= 1000) {
        if (U >= 8000 || L >= 260) cout << "Very Good";
        else cout << "Good";
    }
    else cout << "Bad";
    
}
