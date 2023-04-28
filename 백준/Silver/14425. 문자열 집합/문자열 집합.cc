#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, M, count = 0;
    cin >> N >> M;

    string temp;
    vector<string> v(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < M; i++) {
        cin >> temp;
        if (binary_search(v.begin(), v.end(), temp)) {
            count++;
        }
    }

    cout << count;
}