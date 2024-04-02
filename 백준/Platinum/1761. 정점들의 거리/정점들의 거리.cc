#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
#define pii pair<int, int>
using ll = long long;
using namespace std;

int N, height;
int parent[100001][20] = {0,};
int depth[100001];
int dist[100001][20];
vector<pii> v[100001];

void findparent(int parentnode, int now, int dep, int d) {
    if (!v[now].size()) return;

    parent[now][0] = parentnode;
    depth[now] = dep;
    dist[now][0] = d;

    for (int i = 0; i < v[now].size(); i++) {
        if (v[now][i].first != parentnode) findparent(now, v[now][i].first, dep + 1, v[now][i].second);
    } 
}

int lca(int a, int b) {

    int sum = 0;

    if (depth[a] != depth[b]) {
        if (depth[a] < depth[b]) swap(a, b);

        int dif = depth[a] - depth[b];
        for (int i = 0; dif > 0; i++) {
            if (dif % 2) {
                sum += dist[a][i];
                a = parent[a][i];
            }
            dif = dif>>1;
        }
    }

    if (a != b) {
        for (int j = height; j >= 0; j--) {
            if (parent[a][j] && parent[a][j] != parent[b][j]) {
                sum += dist[a][j] + dist[b][j];
                a = parent[a][j];
                b = parent[b][j];
            }
        }
        sum += dist[a][0] + dist[b][0];
    }

    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int a, b, d;
        cin >> a >> b >> d;
        v[a].push_back({b, d});
        v[b].push_back({a, d});
    }

    findparent(0, 1, 0, 0);

    int temp = N;
    int cnt = 0;
    while (temp > 1) {
        temp = temp >> 1;
        cnt++;
    }
    height = cnt;

    for (int j = 1; j <= height; j++) {
        for (int i = 2; i <= N; i++) {
            // i의 2^{j-1}번째 부모가 있으면
            // i의 2^j번째 부모 = 2^{j-1}번째 부모의 2^{j-1}번째 부모
            // 나의 8번째 부모는 4번째 부모의 4번쨰 부모
            if (parent[i][j-1] != 0) {
                parent[i][j] = parent[parent[i][j-1]][j-1];
                dist[i][j] = dist[i][j - 1] + dist[parent[i][j - 1]][j - 1];
            }
        }
    }

    int M;
    cin >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << endl;
    }

}