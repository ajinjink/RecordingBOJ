#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    double x, y;
    cin >> N;

    vector<pair<double, double> > v;

    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        v.push_back(make_pair(x, y));
    }
    v.push_back(make_pair(v[0].first, v[0].second));

    long long num1 = 0, num2 = 0;
    for (int i = 0; i < N; i++) {
        num1 += v[i].first * v[i+1].second;
        num2 += v[i].second * v[i+1].first;
    }

    
    double res = fabs((num1 - num2) / 2.0);
    res = round(res * 10) / 10.0;
    cout << fixed;
    cout.precision(1);
    cout << res;
    
   
}