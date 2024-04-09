#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
#define ll long long
#define pii pair<int, int>
#define endl '\n'
using namespace std;

ll N, seed, A, B;
set<ll> s;
ll par[1010];

ll find(ll a) {
    if (par[a] == a) return a;
    return par[a] = find(par[a]);
}

bool unite(ll a, ll b) {
    a = find(a);
    b = find(b);

    if (a == b) return false;
    else {
        par[b] = a;
        return true;
    }
}

bool chkgroup() { // 모든 섬 이어졌나 확인
    ll prevg = find(0);
    for (int i = 1; i < N; i++) {
        ll g = find(i);
        if (g != prevg) return false;
        prevg = g;
        
    }
    return true;
}

pii Solve() {
    ll Ei, Eprev, X, Y;
    ll M = 1;

    Eprev = seed % (N*N); // E1
    X = Eprev / N;
    Y = Eprev % N;
    unite(X, Y);
    s.insert(Eprev);

       while (1) {
        M++;

        Ei = (Eprev * A + B) % (N*N);
        X = Ei / N;
        Y = Ei % N;
        if (s.find(Ei) != s.end()) {
            return {0, M}; // 이미 이 페어 연결 시도한 적 있음. 반복
        }
        if (X != Y) unite(X, Y);
        s.insert(Ei);
        Eprev = Ei;
        
        if (chkgroup()) return {1, M}; // 모든 섬 이었음
        
    }


}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while(t--) {
        cin >> N >> seed >> A >> B;
        for (int i = 0; i <= N; i++) par[i] = i;
        s.clear();

        pii res = Solve();
        if (res.first) cout << res.second << endl;
        else cout << 0 << endl;
    }

}
