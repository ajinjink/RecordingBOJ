#include <bits/stdc++.h>
#define pii pair<int, int>
#define tiii tuple<int, int, int>
#define endl '\n'
using namespace std;
using ll = long long;

vector<tuple<int, int, string>> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        string name;
        int point;
        cin >> name >> point;
        v.push_back({point, i, name});
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < M; i++) {
        int score;
        cin >> score;

        int l = 0, r = v.size() - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (get<0>(v[mid]) >= score) r = mid - 1;
            else l = mid + 1;
        }
        
        cout << get<2>(v[l]) << endl;
    }

}
