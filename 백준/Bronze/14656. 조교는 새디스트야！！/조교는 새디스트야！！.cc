#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, temp, cnt = 0;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> temp;
        if (temp != i) {
            cnt++;
        }
    }
    cout << cnt;

}