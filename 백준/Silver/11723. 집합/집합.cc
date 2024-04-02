#include <iostream>
#include <algorithm>
#include <set>
#define endl '\n'
#define pii pair<int, int>
using ll = long long;
using namespace std;

int arr[21] = {0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M;
    cin >> M;

    while (M--) {
        string op; int num;
        cin >> op;

        if (op == "add") {
            cin >> num;
            arr[num] = 1;
        }
        else if (op == "remove") {
            cin >> num;
            arr[num] = 0;
        }
        else if (op == "check") {
            cin >> num;
            if (arr[num]) cout << 1 << endl;
            else cout << 0 << endl;
        }
        else if (op == "toggle") {
            cin >> num;
            arr[num] = !arr[num];
        }
        else if (op == "all") {
            fill(&arr[1], &arr[21], 1);
        }
        else if (op == "empty") fill(&arr[1], &arr[21], 0);
    }
}