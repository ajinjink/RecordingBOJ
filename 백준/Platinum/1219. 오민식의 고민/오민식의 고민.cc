#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <limits.h>
using namespace std;

typedef tuple<int, int, int> edge;

int N, M, start, finish;
long mindist[51] = {0};
long money[51] = {0};
vector<edge> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> start >> finish >> M;
    fill(&mindist[0], &mindist[N + 1], LONG_MIN);

    for (int i = 0; i < M; i++) {
        int a, b, price;
        cin >> a >> b >> price;
        v.push_back(make_tuple(a, b, price));
    }
    for (int i = 0; i < N; i++) {
        cin >> money[i];
    }

    // 역(?) 벨만 포드
    mindist[start] = money[start];

    // 양수 사이클이 전파되도록 충분히 큰 수로 반복
    for (int i = 0; i <= N + 50; i++) {
        for (int j = 0; j < M; j++) {
            int now = get<0>(v[j]);
            int next = get<1>(v[j]);
            int price = get<2>(v[j]);

            // 시작 노드가 미방문
            if (mindist[now] == LONG_MIN) continue;

            // 시작 노드가 양수 사이클에 연결된 노드면
            if (mindist[now] == LONG_MAX) {
                mindist[next] = LONG_MAX; // 다음 노드도 양수 사이클 연결
            }
            else if (mindist[next] < mindist[now] + money[next] - price) {
                mindist[next] = mindist[now] + money[next] - price;
                if (i >= N - 1) { // N - 1 이후에 갱신되는 노드
                    mindist[next] = LONG_MAX; // 는 양수 사이클에 연결
                }
            }
        }
    }

    if (mindist[finish] == LONG_MIN) cout << "gg"; // 도착 불가능
    else if (mindist[finish] == LONG_MAX) cout << "Gee"; // 양수 사이클에 연결된 노드
    else cout << mindist[finish];

}