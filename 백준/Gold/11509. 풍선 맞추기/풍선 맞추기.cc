#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    int cnt = 0;

    int arrow[1000001] = {0};
    for (int i = 0; i < N; i++) {
        if (v[i]) {
            if (arrow[v[i]]) {
                arrow[v[i]]--;
                arrow[v[i] - 1]++;
            }
            else {
                cnt++;
                arrow[v[i] - 1]++;
            }
            v[i] = 0;
        }
    }

    cout << cnt;
    
}