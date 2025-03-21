#include <string>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

long long solution(int n, vector<int> times) {
    sort(times.begin(), times.end());
    ll left = 1, right = (ll)n * times[times.size() - 1];
    ll res;
    while (left <= right) {
        ll mid = (left + right) / 2;
        ll cnt = 0;
        for (int time : times) cnt += (mid / (ll)time);
        if (cnt >= n) {
            res = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return res;
}