#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#define endl '\n'
#define tii tuple<int, int, int>
using ll = long long;
using namespace std;

int N, M, a, b;
vector<tii> v;
bool visited[500000] = {0};

bool compare(tii a, tii b) {
    if (get<0>(a) == get<0>(b)) return get<1>(a) > get<1>(b);

    return get<0>(a) < get<0>(b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        if (a < b) {
            v.push_back({a, b, i});
            v.push_back({a + N, b + N, i});
        }
        else v.push_back({a, b + N, i});
    }
    sort(v.begin(), v.end(), compare);

    int l = 0, r = 0;
    for (auto line : v) {
        int s = get<0>(line), e = get<1>(line);
        int num = get<2>(line);

        if (visited[num]) continue;

        if (l <= s && e <= r) {
            visited[num] = true;
            continue;
        }

        l = s;
        r = e;
    }

    for (int i = 0; i < M; i++) {
        if (!visited[i]) cout << i + 1 << ' ';
    }
}