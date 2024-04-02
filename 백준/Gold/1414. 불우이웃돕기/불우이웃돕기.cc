#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
#define tiii tuple<int, int, int>
using namespace std;

struct compare {
    bool operator() (const tiii &a, const tiii &b) {
        return get<2>(a) > get<2>(b);
    }
};

vector<int> parent;

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
    
    int N, sum = 0;
    cin >> N;

    priority_queue<tiii, vector<tiii>, compare> pq; // 가중치 오름차순
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < N; j++) {
            if (s[j] != '0') {
                int w = s[j];
                if ('a' <= s[j] && s[j] <= 'z') w = w - 'a' + 1;
                else if ('A' <= s[j] && s[j] <= 'Z') w = w - 'A' + 27;
                if (i != j) pq.push({i, j, w});
                sum += w;
            }
        }
    }

    parent.resize(N);
    for (int i = 0; i < N; i++) parent[i] = i;

    int cnt = 0, res = 0;
    while (!pq.empty()) {
        tiii now = pq.top();
        pq.pop();
        if (find(get<0>(now)) != find(get<1>(now))) {
            munion(get<0>(now), get<1>(now));
            res += get<2>(now);
            cnt++;
        }
    }
    
    if (cnt == N - 1) cout << sum - res;
    else cout << -1;

}
