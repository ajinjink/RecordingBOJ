#include <iostream>
#include <algorithm>
// #include <cmath>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M; 
    cin >> N >> M;

    vector<long long> gem(M);
    

    for (int i = 0; i < M; i++) {
        cin >> gem[i];
    }
    sort(gem.begin(), gem.end());

    long long l = 1, r = gem.back();
    

    while (l <= r) {
        long long mid = (l + r) / 2; 
        long long count = 0; 

        for (int i = 0; i < M; i++) {
            count += gem[i] / mid;
            
            if (gem[i] % mid != 0) {
                count++;
            }
            
            
        }

        if (count > N) {
            
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }

    }

    cout << l;

}