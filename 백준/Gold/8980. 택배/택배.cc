#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;
#define endl '\n'
#define all(x) x.begin(), x.end()

bool compare(tuple<int, int, int> a, tuple<int, int, int> b) {
    if (get<1>(a) == get<1>(b)) {
        return get<0>(a) < get<0>(b);
    }
    return get<1>(a) < get<1>(b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, C, M;
    cin >> N >> C >> M;

    vector<tuple<int, int, int>> v; // start, finish, num

    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back(make_tuple(a, b, c));
    }
    sort(v.begin(), v.end(), compare);

    int total = 0;
    vector<int> box(N + 1);

    for (int i = 0; i < v.size(); i++) {
        int start = get<0>(v[i]);
        int finish = get<1>(v[i]);
        int num = get<2>(v[i]);

        int occupied = 0;
        for (int j = start; j < finish; j++) {
            occupied = max(occupied, box[j]);
        }
        int space = min(num, C - occupied);

        for (int j = start; j < finish; j++) { 
            box[j] += space;
        }
        total += space;
    }

    cout << total;
}

