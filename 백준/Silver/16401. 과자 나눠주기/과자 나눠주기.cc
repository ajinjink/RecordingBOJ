#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M, N;
    cin >> M >> N;

    vector<int> v(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    int l = 1, r = v.back();

    while (l <= r) {
        int mid = (l + r) / 2;
        int count = 0;

        for (int i = 0; i < N; i++) {
            count += v[i] / mid;
        }
        
        if (count >= M) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }

    }
    cout << r;

}