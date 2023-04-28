
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v;
unsigned int N, K;

bool checkcut(int len) {
    int count = 0;

    for (int i = 0; i < K; i++) {
        count += v[i] / len;
    }

    if (count >= N) {
        return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    unsigned int temp;
    cin >> K >> N;

    for (int i = 0; i < K; i++) {
        cin >> temp;
        v.push_back(temp);
    }

    sort(v.begin(), v.end());

    unsigned int left = 1, right = v[v.size() - 1];
    unsigned int res = 0;

    while (left <= right) {
        unsigned int mid = (left + right) / 2;

        if (checkcut(mid)) {
            res = max(res, mid);

            left = mid + 1;
        }
        else {
            right = mid - 1;
        }

    }
    cout << res;

}