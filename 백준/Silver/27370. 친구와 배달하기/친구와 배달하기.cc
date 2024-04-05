#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T;
    cin >> T;

    while (T--) {
        int N, Pa, Pb;
        cin >> N >> Pa >> Pb;

        vector<int> d(N);
        for (int i = 0; i < N; i++) cin >> d[i];

        vector<int> same;

        long long total = 0, ad = 0, bd = 0;
        for (int i = 0; i < N; i++) {
            if (abs(Pa - d[i]) > abs(Pb - d[i])) {
                bd += abs(Pb - d[i]);
                total += abs(Pb - d[i]);
            }
            else if (abs(Pa - d[i]) < abs(Pb - d[i])) {
                ad += abs(Pa - d[i]);
                total += abs(Pa - d[i]);
            }
            else {
                same.push_back(abs(Pa - d[i]));
            }
        }

        sort(same.begin(), same.end(), greater<>());
        for (int i = 0; i < same.size(); i++) {
            if (ad < bd) ad += same[i];
            else bd += same[i];
            total += same[i];
        }

        cout << 2 * total << ' ' << 2 * abs(ad - bd) << '\n';
    }

}