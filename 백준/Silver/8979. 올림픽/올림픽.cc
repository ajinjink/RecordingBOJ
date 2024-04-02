#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#define endl '\n'
#define tiiii tuple<int, int, int, int>
using ll = long long;
using namespace std;

vector<tiiii> v;

bool compare(tiiii &a, tiiii &b) {
    if (get<1>(a) != get<1>(b)) {
        return get<1>(a) > get<1>(b);
    } else if (get<2>(a) != get<2>(b)) {
        return get<2>(a) > get<2>(b);
    } else {
        return get<3>(a) > get<3>(b);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    int a, b, c, d;
    for (int i = 0; i < N; i++) {
        cin >> a >> b >> c >> d;
        v.push_back({a, b, c, d});
    }

    sort(v.begin(), v.end(), compare);

    int curr = 0, total = 0;
    a = -1, b = -1, c = -1, d = -1;
    for (int i = 0; i < v.size(); i++) {
        
        total++;
        if (!(b == get<1>(v[i]) && c == get<2>(v[i]) && d == get<3>(v[i]))) curr = total;
        if (get<0>(v[i]) == K) {
            cout << curr;
            break;
        }
        a = get<0>(v[i]), b = get<1>(v[i]), c = get<2>(v[i]), d = get<3>(v[i]);
    }
}