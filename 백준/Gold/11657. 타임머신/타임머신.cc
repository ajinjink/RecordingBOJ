#include <iostream>
#include <vector>
#include <tuple>
#include <limits.h>
using namespace std;

typedef tuple<int, int, int> edge;

int N, M;
long long mindist[501];
vector<edge> v;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    fill(&mindist[0], &mindist[N + 1], LONG_MAX);

    for (int i = 0; i < M; i++) {
        int s, e, t;
        cin >> s >> e >> t;
        v.push_back(make_tuple(s, e, t));
    }

    // 벨만 포드
    mindist[1] = 0;
    for (int i = 1; i < N; i++) { // N보다 하나 적은 수만큼 반복
        for (int j = 0; j < M; j++) {
            int start = get<0>(v[j]);
            int end = get<1>(v[j]);
            int time = get<2>(v[j]);

            if (mindist[start] != LONG_MAX && mindist[end] > mindist[start] + time) {
                mindist[end] = mindist[start] + time;
            }
        }
    }

    bool isCycle = false;

    for (int i = 0; i < M; i++) { // 음수 사이클 확인
        int start = get<0>(v[i]);
        int end = get<1>(v[i]);
        int time = get<2>(v[i]);

        if (mindist[start] != LONG_MAX && mindist[end] > mindist[start] + time) {
            isCycle = true;
        }
    }

    if (isCycle) {
        cout << -1;
        return 0;
    }

    for (int i = 2; i <= N; i++) {
        if (mindist[i] == LONG_MAX) cout << -1 << '\n';
        else cout << mindist[i] << '\n';
    }

}