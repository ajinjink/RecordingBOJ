#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
#define pii pair<int, int>
using ll = long long;
using namespace std;

int tree[10001] = {0};

void postorder(int start, int end) {
    if (start >= end) return;

    if (start == end - 1) {
        cout << tree[start] << endl;
        return;
    }

    // 전위 순위 특 : 첫 번째가 루트 -> 왼쪽 트리 주루룩 -> 오른쪽 트리 주루룩
    // 첫 번째보다 더 큰 게 나오면, 거기부터는 루트의 오른쪽
    int index = start + 1;
    while (index < end) { // 시작부터 끝까지 훑으면서
        if (tree[start] < tree[index]) break; // 루트보다 큰 거 나오는 인덱스 찾아
        index++;
    }

    postorder(start+1, index); // 왼쪽 트리
    postorder(index, end); // 오른쪽 트리
    cout << tree[start] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int node;
    int i = 0;
    while (cin >> node) tree[i++] = node;

    postorder(0, i);
}