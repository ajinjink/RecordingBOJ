#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> v(N);
    long long sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> v[i];
        sum += v[i];
    }

    if (sum % 3) {
        cout << "NO";
        return 0;
    }

    int two = 0;
    for (int i = 0; i < N; i++) {
        two += v[i] / 2;
    }

    if (two >= sum / 3) cout << "YES";
    else cout << "NO";


}