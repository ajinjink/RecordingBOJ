#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
#define pii pair<int, int>
using ll = long long;
using namespace std;

int n;
int pre[1001];
int in[1001];
vector<int> post;

void init() {
    fill(&pre[0], &pre[1001], 0);
    fill(&in[0], &in[1001], 0);
    post.clear();
}

void divide(int pl, int pr, int il, int ir) { // preorder start end, inorder start end
    if (pl > pr || il > ir) return;

    for (int i = 0; i < pr - pl; i++) {
        int root = pre[pl];
        if (in[il + i] == root) {
            divide(pl + 1, pl + i + 1, il, il + i); // 왼
            divide(pl + i + 1, pr, il + i + 1, ir); // 오
            post.push_back(root); // 중간
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin >> t;

    while(t--) {

        init();

        cin >> n;

        for (int i = 0; i < n; i++) cin >> pre[i];
        for (int i = 0; i < n; i++) cin >> in[i];

        divide(0, n, 0, n);

        for (int i = 0; i < post.size(); i++) cout << post[i] << ' ';
        cout << endl;
    }
}