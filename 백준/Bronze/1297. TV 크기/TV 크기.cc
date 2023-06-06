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

    int D, H, W;
    cin >> D >> H >> W;

    double k = sqrt((double(pow(D, 2))) / (pow(H, 2) + pow(W, 2)));

    cout << int(k * H) << ' ' << int(k * W);



}

