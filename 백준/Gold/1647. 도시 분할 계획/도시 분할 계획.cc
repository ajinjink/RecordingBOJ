#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#define endl '\n'
#define tiii tuple<int, int, int>
using namespace std;

static int N, M;
static int parent[100001];
vector<tiii> v;
vector<int> edges;

bool compare(tiii a, tiii b) {
    return get<2>(a) < get<2>(b);
}

int find(int a) {
    if (a == parent[a]) return a;
    else return parent[a] = find(parent[a]);
}

void munion(int a, int b) {
    a = find(a);
    b = find(b);

    if (a != b) parent[b] = a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;

    for (int i = 1; i <= N; i++) parent[i] = i;

    int A, B, C;
    for (int i = 0; i < M; i++) {
        cin >> A >> B >> C;
        v.push_back({A, B, C});
    }
    sort(v.begin(), v.end(), compare); // 가중치 기준 오름차순

    for (int i = 0; i < v.size(); i++) {
        int w = get<2>(v[i]);
        int a = get<0>(v[i]);
        int b = get<1>(v[i]);

        if (find(a) != find(b)) { // 사이클 발생 안 하면
            munion(a, b); // 연결
            edges.push_back(w);
        }
    }
    // v는 이미 가중치 기준 오름차순
    // 따라서 edges에 들어가는 w도 오름차순

    int res = 0;
    for (int i = 0; i < edges.size() - 1; i++) res += edges[i]; // 제일 큰 w만 제외

    cout << res;
    
}