#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
#define endl '\n'

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, M;
    cin >> N >> M;

    vector<int> d(N + M + 1);

    set<pair<int, int>> m1;
    set<pair<int, int>> m2;
    for (int i = 1; i <= N; i++) {
        cin >> d[i];
        m1.insert({d[i], i});
    }
    for (int i = N + 1; i <= N + M; i++) {
        cin >> d[i];
        m2.insert({d[i], i});
    }

    int K;
    cin >> K;
    while (K--) {
        char op;
        cin >> op;

        if (op == 'U') {
            int x, y;
            cin >> x >> y;
            if (x <= N) {
                m1.erase({d[x], x});
                d[x] = y;
                m1.insert({d[x], x});
            }
            else {
                m2.erase({d[x], x});
                d[x] = y;
                m2.insert({d[x], x});
            }
        }
        else if (op == 'L') {
            cout << m1.begin() -> second << ' ' << m2.begin() -> second << endl;
        }
    }
}