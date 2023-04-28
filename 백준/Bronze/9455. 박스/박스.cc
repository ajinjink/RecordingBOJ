#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int m, n, box, count = 0;
        cin >> m >> n;
        vector<int> v[100];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> box;
                if (box) {
                    v[j].push_back(i);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            int pointer = m - 1;
            for (int j = v[i].size() - 1; j >= 0; j--) {
                count += pointer - v[i][j];
                pointer--;
            }
        }
        cout << count << '\n';

    }
}