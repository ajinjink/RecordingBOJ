#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
#define pii pair<int, int>
using ll = long long;
using namespace std;

int n;
int inarr[100001];
int postarr[100001];
vector<int> prearr;

void divide(int il, int ir, int pl, int pr) { // inarr start end, postarr start end
    if (il > ir || pl > pr) return;

    for (int i = 0; i < ir - il; i++) {
        int root = postarr[pr - 1];
        if (inarr[il + i] == root) {
            prearr.push_back(root);
            divide(il, il + i, pl, pl + i);
            divide(il + i + 1, ir, pl + i, pr - 1);
        }
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> inarr[i];
    for (int i = 0; i < n; i++) cin >> postarr[i];
    
    divide(0, n, 0, n);
    for (int i = 0; i < prearr.size(); i++) {
        cout << prearr[i] << ' ';
    }
}