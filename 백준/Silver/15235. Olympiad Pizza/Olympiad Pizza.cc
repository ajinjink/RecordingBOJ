#include <iostream>
#include <algorithm>
#include <queue>
#define pii pair<int, int>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;

    queue<pii> q;
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        q.push({i, a}); // index, slices
    }

    vector<int> res(N);
    int time = 0;
    while (!q.empty()) {
        time++;
        pii t = q.front();
        q.pop();
        t.second--;
        if (t.second) q.push({t.first, t.second});
        else res[t.first] = time;
    }

    for (int i = 0; i < N; i++) cout << res[i] << ' ';

}