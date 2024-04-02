#include <iostream>
#include <vector>
#include <tuple>
#include <limits.h>
using namespace std;

typedef tuple<int, int, int> edge;

int N, M, W;
long long mindist[501];
vector<edge> v;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        cin >> N >> M >> W;

        v.clear();
        fill(&mindist[0], &mindist[N + 1], INT_MAX);

        for (int i = 0; i < M; i++) {
            int s, e, t;
            cin >> s >> e >> t;
            v.push_back(make_tuple(s, e, t));
            v.push_back(make_tuple(e, s, t));
        }
        for (int i = 0; i < W; i++) {
            int s, e, t;
            cin >> s >> e >> t;
            v.push_back(make_tuple(s, e, -t));
        }

        // 벨만 포드
        mindist[1] = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < v.size(); j++) { // 경로의 개수
                int start = get<0>(v[j]);
                int end = get<1>(v[j]);
                int time = get<2>(v[j]);

                if (mindist[end] > mindist[start] + time) {
                    mindist[end] = mindist[start] + time;
                }
            }
        }

        bool isCycle = false;

        for (int i = 0; i < v.size(); i++) { // 음수 사이클 확인
            int start = get<0>(v[i]);
            int end = get<1>(v[i]);
            int time = get<2>(v[i]);

            if (mindist[end] > mindist[start] + time) {
                isCycle = true;
                break;
            }
        }

        if (isCycle) {
            cout << "YES\n"; 
        }
        else cout << "NO\n";
    }

}