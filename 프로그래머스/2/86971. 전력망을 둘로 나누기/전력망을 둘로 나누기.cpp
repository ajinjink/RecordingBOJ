#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

int bfs(int start, int ban, int n, vector<vector<int>> v) {
    vector<bool> visited(n + 1, false);
    queue<int> q;
    q.push(start);
    visited[start] = true;
    int nodecnt = 1;
    
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        
        for (int next : v[curr]) {
            if (!visited[next] && next != ban) {
                visited[next] = true;
                q.push(next);
                nodecnt++;
            }
        }
    }
    return nodecnt;
}

int solution(int n, vector<vector<int>> wires) { // 송전탑 개수, 전선 연결 정보
    vector<vector<int>> v(n + 1);
    for (vector<int> temp : wires) {
        v[temp[0]].push_back(temp[1]);
        v[temp[1]].push_back(temp[0]);
    }
    
    int res = 1e9;
    for (vector<int> temp : wires) {
        // temp 연결을 끊어
        int cnt = bfs(temp[0], temp[1], n, v);
        res = min(res, abs(n - 2*cnt));
    }
    
    return res;
}