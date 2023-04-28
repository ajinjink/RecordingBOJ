#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, temp, max = 0;
    cin >> N >> M;
    
    vector<int> v;

    long long sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        v.push_back(temp);
        sum += temp;
        if (temp > max) {
            max = temp;
        }
    }

    long long l = max, r = sum;
    int mid;


    while (l <= r) {
        mid = (l + r) / 2;
        int len = 0, cnt = 0;

        for (int i = 0; i < N; i++) {
            
            if (len + v[i] > mid) {
                cnt++;
                len = 0;
            }
            len += v[i];
            
        }
        if (len != 0) {
            cnt++;
        }


        if (cnt > M) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }


    }

    cout << l;


    

}