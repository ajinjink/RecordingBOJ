
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

    int N, W, H, L;
    cin >> N >> W >> H >> L;
    int num = (W / L) * (H / L);

    if (num >= N) {
        cout << N;
    }
    else {
        cout << num;
    }

    
}
