#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int K;
    cin >> K;

    for (int k = 1; k <= K; k++) {
        int n, t; // 모자 개수, 써 본 개수
        cin >> n >> t;

        vector<int> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];

        int upper = 2000, lower = -1;
        vector<int> perfect;
        bool inconsistant = false;
        for (int i = 0; i < t; i++) {
            int c, f;
            cin >> c >> f;

            if (f == 1) { // too small
                if (c >= upper) inconsistant = true;
                lower = max(lower, c + 1); 
            }
            else if (f == -1) { // too large
                if (c <= lower) inconsistant = true;
                upper = min(upper, c - 1); 
            }
            else if (f == 0) { // perfect fit
                perfect.push_back(c);
                upper = lower = c;
            }
        }

        cout << "Data Set " << k << ':' << endl;

        if (lower > upper || inconsistant) {
            cout << "Inconsistent feedback" << endl << endl;
            continue;
        }

        if (perfect.size() > 1) {
            int temp = perfect[0];
            for (int j = 1; j < perfect.size(); j++) {
                if (temp != perfect[j]) {
                    inconsistant = true;
                    break;
                }
            }
            if (inconsistant) {
                cout << "Inconsistent feedback" << endl << endl;
                continue;
            }
        }

        if (t == 0) {
            cout << n << endl << endl;
            continue;
        }

        if (perfect.size() == 1) {
            cout << 1 << endl << endl;
            continue;
        }

        int cnt = 0;
        for (int s : v) {
            if (lower <= s && s <= upper) cnt++;
            else if (s >= upper) break;
        }

        cout << cnt << endl << endl;
        
    }

}