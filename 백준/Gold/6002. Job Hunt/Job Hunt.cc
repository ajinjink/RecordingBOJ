#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;

typedef tuple<int, int, int> node;
int mindist[221];
vector<node> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int D, P, C, F, S;
    cin >> D >> P >> C >> F >> S;

    for (int i = 0; i < P; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back(make_tuple(a, b, -D));
    }
    for (int i = 0; i < F; i++) {
        int j, k, t;
        cin >> j >> k >> t;
        v.push_back(make_tuple(j, k, -D + t));
    }

    fill(&mindist[0], &mindist[C + 1], 1e9);
    mindist[S] = -D;
    for (int i = 1; i < C; i++) {
        for (int j = 0; j < v.size(); j++) {
            int from = get<0>(v[j]);
            int to = get<1>(v[j]);
            int cost = get<2>(v[j]);

            if (mindist[from] == 1e9) continue;
            if (mindist[to] > mindist[from] + cost) mindist[to] = mindist[from] + cost;
        }
    }

    bool isCycle = false;
    for (int i = 0; i < v.size(); i++) {
        int from = get<0>(v[i]);
        int to = get<1>(v[i]);
        int cost = get<2>(v[i]);

        if (mindist[from] == 1e9) continue;
        if (mindist[to] > mindist[from] + cost) isCycle = true; break;
    }

    if (isCycle) cout << -1;
    else {
        int res = 1e9;
        for (int i = 1; i <= C; i++) {
            res = min(res, mindist[i]);
        }
        cout << -res;
    }

}