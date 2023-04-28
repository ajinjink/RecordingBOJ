#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;
    char comma;

    vector<int> v1(N);
    vector<int> v2;
    for (int i = 0; i < N - 1; i++) {
        cin >> v1[i] >> comma;
    }
    cin >> v1[N - 1];

    for (int t = 0; t < K; t++) {
        if (t % 2 == 0) {
            for (int i = 1; i < v1.size(); i++) {
                v2.push_back(v1[i] - v1[i - 1]);
            }
            v1.clear();
        }
        else {
            for (int i = 1; i < v2.size(); i++) {
                v1.push_back(v2[i] - v2[i - 1]);
            }
            v2.clear();
        }
    }

    if (K % 2 == 0) {
        cout << v1[0];
        for (int i = 1; i < v1.size(); i++) {
            cout << ',' << v1[i];
        }
    }
    else {
        cout << v2[0];
        for (int j = 1; j < v2.size(); j++) {
            cout << ',' << v2[j];
        }
    }

}