#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#define endl '\n'
#define ll long long
using namespace std;

vector<pair<ll, int>> tree; // minval, index
priority_queue<ll> pq;

void treeinit(int i) {
    while (i != 1) {
        if (tree[i].first < tree[i / 2].first) tree[i/2] = tree[i];
        i--;
    }
}

void getmin(int s, int e) {
    if (s > e) return;
    
    int ss = s, ee = e;
    pair<ll, int> minval = tree[s];
    while (ss <= ee) {
        if (ss % 2 == 1) {
            if (tree[ss].first < minval.first) {
                minval = tree[ss];
            }
            ss++;
        }
        if (ee % 2 == 0) {
            if (tree[ee].first < minval.first) {
                minval = tree[ee];
            }
            ee--;
        }
        ss /= 2;
        ee /= 2;
    }

    int minindex = minval.second;
    ll area = (e - s + 1) * minval.first;
    if (pq.empty() || pq.top() < area) pq.push(area);

    getmin(s, minindex - 1);
    getmin(minindex + 1, e);

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    tree.clear();
    int len = n, height = 0;
    while (len) {
        len /= 2;
        height++;
    }
    tree.resize(pow(2, height + 1) + 1);
    for (int i = 0; i < tree.size(); i++) tree[i] = {1e9, i}; // val, index
    int startindex = pow(2, height + 1) / 2 - 1;

    for (int i = 1; i <= n; i++) cin >> tree[startindex + i].first;
    treeinit(pow(2, height + 1) - 1);

    while (pq.size()) pq.pop();
    getmin(startindex + 1, startindex + n);
    cout << pq.top() << endl;

}