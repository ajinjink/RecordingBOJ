#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
#define pii pair<int, int>
using ll = long long;
using namespace std;

int arr[22] = {0}, res[22] = {0}, cnt = 0;

void printarr() {
    for (int i = 0; i <= 20; i++) cout << res[i] << ' ';
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int P;
    cin >> P;

    while (P--) {
        fill(&arr[0], &arr[21], 0);
        fill(&res[0], &res[21], 0);
        cnt = 0;

        int T;
        cin >> T;
        for (int i = 1; i <= 20; i++) cin >> arr[i];

        res[1] = arr[1];

        for (int i = 2; i <= 20; i++) {
            if (res[i - 1] < arr[i]) res[i] = arr[i];
            else {
                for (int j = i - 1; j >= 0; j--) {
                    if (res[j] < arr[i]) {
                        for (int k = i; k > j; k--) {
                            res[k + 1] = res[k];
                        }
                        res[j + 1] = arr[i];

                        cnt += (i - j - 1);
                        break;
                    }
                }
            }
        }
        cout << T << ' ' << cnt << endl;
    }

}