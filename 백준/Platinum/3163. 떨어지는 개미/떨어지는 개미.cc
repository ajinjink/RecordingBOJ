#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define endl '\n'
#define pii pair<int, int>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin >> t;

    while (t--) {
        int n, l, k, p, a;
        cin >> n >> l >> k;

        vector<int> id(n, 0);
        vector<int> plus;
        vector<int> minus;
        vector<pii> arr(n, {0, 0});

        for (int i = 0; i < n; i++) {
            cin >> p >> a;
            if (a > 0) plus.push_back(l - p);
            else minus.push_back(p);
            id[i] = a;
        }
        sort(plus.rbegin(), plus.rend());
        sort(minus.begin(), minus.end());

        for (int i = 0; i < n; i++) arr[i].second = id[i];
        for (int i = 0; i < minus.size(); i++) {
            arr[i].first = minus[i];
        }
        for (int i = 0; i < plus.size(); i++) {
            arr[minus.size() + i].first = plus[i];
        }

        vector<int> fall;
        int left = 0, right = n - 1;
        for (int i = 0; i < k; i++) {
            if (arr[left].first == arr[right].first) {
                if (arr[left].second < arr[right].second) {
                    fall.push_back(arr[left].second);
                    left++;
                }
                else {
                    fall.push_back(arr[right].second);
                    right--;
                }
            }
            else if (arr[left].first < arr[right].first) {
                fall.push_back(arr[left].second);
                left++;
            }
            else {
                fall.push_back(arr[right].second);
                right--;
            }
        }

        cout << fall[k - 1] << endl;


    }


}
