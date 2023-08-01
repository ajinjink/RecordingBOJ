#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    while (N--) {
        int r, e, c;
        cin >> r >> e >> c;

        if (r < e - c) cout << "advertise\n";
        if (r == e - c) cout << "does not matter\n";
        if (r > e - c) cout << "do not advertise\n";
    }
    
}