#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
#define pii pair<int, int>
using ll = long long;
using namespace std;

int N;
int tree[26][2]; // 각 노드마다 left, right

void preorder(int now) {
    if (now == -1) return;

    cout << (char)(now + 'A');
    preorder(tree[now][0]); // 왼쪽 탐색
    preorder(tree[now][1]); // 오른쪽 탐색
}

void inorder(int now) {
    if (now == -1) return;

    inorder(tree[now][0]); // 왼쪽 탐색
    cout << (char)(now + 'A');
    inorder(tree[now][1]); // 오른쪽 탐색
}

void postorder(int now) {
    if (now == -1) return;

    postorder(tree[now][0]); // 왼쪽 탐색
    postorder(tree[now][1]); // 오른쪽 탐색
    cout << (char)(now + 'A');
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;

    for (int i = 0; i < N; i++) {
        char node, left, right;
        cin >> node >> left >> right;
        node -= 'A';

        if (left == '.') tree[node][0] = -1;
        else tree[node][0] = left - 'A';

        if (right == '.') tree[node][1] = -1;
        else tree[node][1] = right - 'A';
    }

    preorder(0);
    cout << endl;
    inorder(0);
    cout << endl;
    postorder(0);
    cout << endl;


}