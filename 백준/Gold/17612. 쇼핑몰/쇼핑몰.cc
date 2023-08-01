#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct customer {
    int id;
    int time;
    int cashier;

    customer(int _id, int _time, int _cashier) : id(_id), time(_time), cashier(_cashier) {}
};

struct compare {
    bool operator() (customer c1, customer c2) {
        if (c1.time == c2.time) {
            return c1.cashier > c2.cashier;
        }
        return c1.time > c2.time;
    }
};

bool vcmp(customer c1, customer c2) {
    if (c1.time == c2.time) {
        return c1.cashier > c2.cashier;
    }
    return c1.time < c2.time;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, k, id, w;
    cin >> N >> k; // N 명의 손님, k 개의 계산대

    priority_queue<customer, vector<customer>, compare > pq; // 회원번호, 시간, 계산대번호

    vector<customer> v;

    for (int i = 0; i < N; i++) {
        cin >> id >> w; 

        if (i < k) {
            pq.push(customer(id, w, i));
        }
        else {
            pq.push(customer(id, w + pq.top().time, pq.top().cashier));
            v.push_back(pq.top());
            pq.pop();
        }
    }

    long long res = 0;

    while (!pq.empty()) {
        v.push_back(pq.top());
        pq.pop();
    }

    sort(v.begin(), v.end(), vcmp);

    for (int i = 0; i < v.size(); i++) {
        res += 1LL * (i + 1) * v[i].id;
    }

    cout << res;
}
