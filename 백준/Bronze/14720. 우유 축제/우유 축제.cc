#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, count = 0, now, res = 0;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> now;
        if (now == count % 3) {
            res++;
            count++;
        }
    }
    cout << res;
    
}
