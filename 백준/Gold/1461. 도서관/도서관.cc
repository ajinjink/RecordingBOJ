#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    priority_queue<int> plist;
    priority_queue<int, vector<int>, greater<int> > nlist;

    for (int i = 0; i < N; i++) {
        int dist;
        cin >> dist;
        if (dist > 0) plist.push(dist);
        else nlist.push(dist);
    }

    int res = 0;
    int maxdist;
    if (!plist.empty() && !nlist.empty()) maxdist = max(plist.top(), -nlist.top());
    else if (plist.empty()) maxdist = -nlist.top();
    else if (nlist.empty()) maxdist = plist.top();

    while (!plist.empty()) {
        int dist = plist.top();
        for (int i = 0; i < M; i++) {
            plist.pop();
            if (plist.empty()) break;
        }
        res += 2 * dist;
    }
    while (!nlist.empty()) {
        int dist = -nlist.top();
        for (int i = 0; i < M; i++) {
            nlist.pop();
            if (nlist.empty()) break;
        }
        res += 2 * dist;
    }
    
    cout << res - maxdist;

}