#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int table[300][300] = {0,};
int visited[300][300] = {0,};
int I, cura, curb, desta, destb, res;

queue<pair<int, int> > q;
vector<int> result;

void bfs() {
    while (!q.empty()) {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();

        
        for (int i = 0; i < 8; i++) {
            int nexta = a + dy[i];
            int nextb = b + dx[i];
            if (nexta == desta && nextb == destb) {
                result.push_back(visited[a][b] + 1);
            }
            if (nexta >= 0 && nexta < I && nextb >= 0 && nextb < I && !visited[nexta][nextb]) {
                visited[nexta][nextb] = visited[a][b] + 1;
                q.push(make_pair(nexta, nextb));
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> I;
        cin >> cura >> curb >> desta >> destb;

        if (cura == desta && curb == destb) {
            cout << 0 << '\n';
            continue;
        }

        q.push(make_pair(cura, curb));
        bfs();

        sort(result.begin(), result.end());
        cout << result[0] << '\n';

        memset(visited, 0, sizeof(visited));
        result.clear();
    }

}