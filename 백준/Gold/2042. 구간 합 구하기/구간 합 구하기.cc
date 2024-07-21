#include <iostream>
#include <vector>
#include <cmath>
#define ll long long
#define endl '\n'
using namespace std;

int N, M, K;
vector<ll> v;

void init(ll index) {
    while (index != 1) {
        v[index / 2] += v[index];
        index--;
    }
}

void change(ll place, ll num) {
    ll diff = v[place] - num;

    while (place) {
        v[place] -= diff;
        place /= 2;
    }
}

ll sum(ll a, ll b) {
    ll res = 0;

    while (a <= b) {
        if (a % 2 == 1) {
            res += v[a];
            a++;
        }
        if (b % 2 == 0) {
            res += v[b];
            b--;
        }
        a /= 2;
        b /= 2;
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M >> K;

    int h = 0, len = N;
    while (len) {
        len /= 2;
        h++;
    }
    v.resize(pow(2, h + 1) + 1, 0);
    int left = pow(2, h + 1) / 2 - 1;
    
    for (int i = 1; i <= N; i++) cin >> v[left + i];
    init(pow(2, h + 1) - 1);

    for (int i = 0; i < M + K; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        if (a == 1) { // b번째 수를 c로 변경
            change(left + b, c);
        } else if (a == 2) { // b번째부터 c번째까지 부분합 출력
            cout << sum(left + b, left + c) << endl;
        }
    }

    return 0;
}