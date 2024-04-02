#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <cmath>
#define endl '\n'
#define pii pair<int, int>
#define tiii tuple<int, int, int>
using ll = long long;
using namespace std;

int N;
vector<tuple<int, int, double>> v;
int parent[101] = {0};
vector<pair<double, double>> star;

bool compare(tuple<int, int, double> a, tuple<int, int, double> b) {
    return get<2>(a) < get<2>(b);
}

int find(int a) {
    if (parent[a] == a) return a;
    else return parent[a] = find(parent[a]);
}

void union_func(int a, int b) {
    a = find(a);
    b = find(b);

    if (a != b) parent[b] = a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    
    for (int i = 0; i <= N; i++) parent[i] = i;

    for (int i = 0; i < N; i++) {
        double x, y;
        cin >> x >> y;
        star.push_back({x, y});
    }

    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            double dist = sqrt(pow(fabs(star[i].first - star[j].first), 2) + pow(fabs(star[i].second - star[j].second), 2));
            // cout << dist << endl;
            v.push_back({i + 1, j + 1, dist});
        }
    }
    sort(v.begin(), v.end(), compare); // 거리 기준 오름차순

    double res;
    for (int i = 0; i < v.size(); i++) {
        int a = get<0>(v[i]);
        int b = get<1>(v[i]);
        double w = get<2>(v[i]);

        if (find(a) != find(b)) {
            union_func(a, b);
            res += w;
        }
    }

    cout << fixed;
    cout.precision(2);
    cout << res;

}