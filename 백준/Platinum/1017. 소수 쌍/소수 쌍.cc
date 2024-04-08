#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
vector<int> g[120];
int par[120];
vector<int> n1, n2; 
bool visited[120];
bool isPrime[2010];

void primeinit() {
    for (int i = 2; i < 2010; i++) isPrime[i] = 1;
    for (int i = 1; i < 2010; i++) {
        if (!isPrime[i]) continue;
        for (int j = 2 * i; j < 2010; j += i) isPrime[j] = 0;
    }
}

int match(int v) { 
    for (auto n : g[v]) {
        if (visited[n]) continue;
        visited[n] = 1;
        if (!isPrime[n1[v] + n2[n - 60]]) continue;
        if (par[n] == -1 || match(par[n])) { 
            par[n] = v; 
            return 1;
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    bool even = true; // a가 짝수 -> n2
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        if (i == 0 && a % 2) even = false; // a가 홀수 -> n1
        if (a % 2) n1.push_back(a);
        else n2.push_back(a);
    }

    if (n1.size() != n2.size()) {
        cout << -1;
        return 0;
    }

    if (even) swap(n1, n2); // a를 n1에 고정하고 싶음

    primeinit();

    for (int i = 0; i < n1.size(); i++) {
        for (int j = 0; j < n2.size(); j++) {
            if (isPrime[n1[i] + n2[j]]) g[i].push_back(60 + j); // 연결될 수 있는 노드의 인덱스 저장
        }
    }

    vector<int> res;
    for (int t = 0; t < n2.size(); t++) {

        fill(&par[0], &par[120], -1);
        if (!isPrime[n1[0] + n2[t]]) {
            continue;
        }

        int cnt = 1;
        par[60 + t] = n1[0];
        for (int i = 1; i < n1.size(); i++) { // 두 번째 수부터 매칭
            fill(&visited[0], &visited[121], 0);
            visited[0] = visited[60 + t] = 1; // 첫 번째 수, 첫 번째 수와 매칭된 수는 이미 끝
            if (match(i)) cnt++;
        }

        if (cnt == n2.size()) res.push_back(n2[t]);

    }

    if (res.size()) {
        sort(res.begin(), res.end());
        for (int i = 0; i < res.size(); i++) cout << res[i] << ' ';
    }
    else cout << -1;


}