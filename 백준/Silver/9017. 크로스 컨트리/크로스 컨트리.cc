#include <bits/stdc++.h>
#define endl '\n'
#define tiii tuple<int, int, int>
using ll = long long;
using namespace std;

int N;
int team[201]; // 선수 몇 명인지
int res[201]; // 4명 점수 총합
int res5[201];
int cnt[201]; // 4명까지 카운팅
int arr[1001]; // 들어온 순서
vector<tiii> v;

bool compare(tiii a, tiii b) {
    if (get<0>(a) == get<0>(b)) return get<1>(a) < get<1>(b);
    return get<0>(a) < get<0>(b);
}

void init() {
    v.clear();
    fill(&team[0], &team[201], 0);
    fill(&res[0], &res[201], 0);
    fill(&res5[0], &res5[201], 0);
    fill(&cnt[0], &cnt[201], 0);
    fill(&arr[0], &arr[1001], 0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    while (T--) {

        init();

        cin >> N;

        for (int i = 0; i < N; i++) {
            cin >> arr[i];
            team[arr[i]]++;
        }

        int score = 1;
        for (int i = 0; i < N; i++) {
            if (team[arr[i]] < 6) continue;

            if (cnt[arr[i]] < 4) {
                res[arr[i]] += score;
                cnt[arr[i]]++;
            }
            else if (cnt[arr[i]] == 4) {
                res5[arr[i]] += score;
                cnt[arr[i]]++;
            }
            score++;
        }

        for (int i = 1; i <= 200; i++) {
            if (team[i] == 6) {
                v.push_back({res[i], res5[i], i});
            }
        }

        sort(v.begin(), v.end(), compare);

        cout << get<2>(v[0]) << endl;

    }

}
