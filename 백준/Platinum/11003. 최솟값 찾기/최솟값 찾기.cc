#include <iostream>
#include <deque>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, L;
    cin >> N >> L;

    deque<pair<int, int> > d;

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;

        while (d.size() && d.back().second > num) {
            d.pop_back();
        }

        d.push_back(make_pair(i, num)); // index, num

        if (d.front().first <= i - L) {
            d.pop_front();
        }
        
        cout << d.front().second << ' ';
    }

}