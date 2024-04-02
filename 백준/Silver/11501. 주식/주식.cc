#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <cstring>
#include <sstream>
#include <limits.h>
#define endl '\n'
#define pii pair<int, int>
#define tiiii tuple<int, int, int, int>
using ll = long long;
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;

        vector<ll> v(N);

        for (int i = 0; i < N; i++) {
            cin >> v[i];
        }

        int maxcost = 0, index = 0;
        vector<pii> temp;
        for (int i = N - 1; i >= 0; i--) {
            if (v[i] > maxcost) {
                maxcost = v[i];
                index = i;
                temp.push_back({maxcost, i});
            }
        }
        sort(temp.begin(), temp.end(), greater());


        int flag = 0;
        ll res = 0;
        for (int i = 0; i < temp.size(); i++) {
            if (temp[i].second >= flag) {
                for (int j = flag; j < temp[i].second; j++) {
                    if (temp[i].first - v[j] > 0)
                        res += temp[i].first - v[j];
                }
                flag = temp[i].second + 1;
            }
        }
        

        cout << res << endl;
        
    }
    
}
