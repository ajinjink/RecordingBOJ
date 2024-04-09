#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define endl '\n'
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        double N, X, Y;
        cin >> N >> X >> Y;

        vector<double> v(N + 1);
        double time = 1e9;
        for (int i = 1; i <= N; i++) {
            cin >> v[i];
            if (i != N) time = min(time, X / v[i]);
        }

        if ((X / v[N]) < time) {
            cout << 0 << endl;
            continue;
        }
        if (((X - Y) / v[N]) + 1 >= time) {
            cout << -1 << endl;
            continue;
        }
        
        if (ceil(X - (time - 1)*v[N]) == (X - (time - 1)*v[N])) cout << X - (time - 1)*v[N] + 1 << endl;
        else cout << ceil(X - (time - 1)*v[N]) << endl;

    }
}