#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <cstring>
#include <limits.h>
#define endl '\n'
#define pii pair<int, int>
#define tiiii tuple<int, int, int, int>
using ll = long long;
using namespace std;

int arr[101][101] = {0,}; // 팀, 문제 번호 {점수}
int cnt[101] = {0}; // 총 제출 수
int timelog[101] = {0}; // 마지막 제출

bool compare(tiiii a, tiiii b) { // 팀, 점수, 총 제출 수, 마지막 제출
    if (get<1>(a) == get<1>(b) && get<2>(a) == get<2>(b)) return get<3>(a) < get<3>(b);
    if (get<1>(a) == get<1>(b)) return get<2>(a) < get<2>(b);
    return get<1>(a) > get<1>(b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        int n, k, t, m;
        cin >> n >> k >> t >> m; // 팀 수, 문제 수, 우리팀 ID, 로그 엔트리 수

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                arr[i][j] = 0;
            }
        }
        fill(&cnt[0], &cnt[101], 0);
        fill(&timelog[0], &timelog[101], 0);

        for (int h = 1; h <= m; h++) {
            int i, j, s;
            cin >> i >> j >> s; // 팀, 문제 번호, 점수

            if (arr[i][j] < s) {
                arr[i][j] = s;
            }
            cnt[i]++;
            timelog[i] = h;
        }

        vector<tiiii> v; // 팀, 점수, 총 제출 수, 마지막 제출
        for (int i = 1; i <= n; i++) {
            int score = 0;
            for (int j = 1; j <= k; j++) {
                score += arr[i][j];
            }
            v.push_back({i, score, cnt[i], timelog[i]});
        }
        sort(v.begin(), v.end(), compare);

        for (int h = 0; h < v.size(); h++) {
            if (get<0>(v[h]) == t) {
                cout << h + 1 << endl;
                break;
            }
        }

    }

}
