#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
#define pii pair<int, int>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        int s;
        cin >> s;

        string r;
        if (s > 4500) r = "Round 1";
        else if (s > 1000) r = "Round 2";
        else if (s > 25) r = "Round 3";
        else r = "World Finals";
        
        cout << "Case #" << i << ": " << r << endl;
    }


}