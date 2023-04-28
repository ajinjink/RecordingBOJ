#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, d, k, c, temp; // 초밥 수, 초밥 종류, 연속 먹는 수, 쿠폰
    cin >> N >> d >> k >> c;

    vector<int> v;
    int cnt[3001] = {0};
    cnt[c] = 1;
    int count = 1;

    for (int i = 0; i < N; i++) {
        cin >> temp;
        v.push_back(temp);
        if (i < k) {
            cnt[temp]++;
            if (cnt[temp] == 1) {
                count++;
            }
        }
    }

    int begin = 0, end = k - 1;
    int res = 0;

    while (begin < N) {
        cnt[v[begin]]--;
        if (cnt[v[begin]] == 0) {
            count--;
        }
        begin++;
        end = (end + 1) % N;
        cnt[v[end]]++;
        if (cnt[v[end]] == 1) {
            count++;
        }
        res = max(res, count);
    }

    cout << res;

}
