#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define endl '\n'
#define pii pair<int, int>
using ll = long long;
using namespace std;

int N, M, K;
vector<long> tree;

void maketree(int i) {
    while (i != 1) {
        tree[i / 2] += tree[i];
        i--;
    }
}

void change(int index, long val) { // 트리 값 변경
    long diff = val - tree[index];

    while (index > 0) {
        tree[index] = tree[index] + diff;
        index /= 2;
    }
}

long getsum(int s, int e) {
    long sum = 0;

    while (s <= e) {
        if (s % 2 == 1) {
            sum += tree[s];
            s++;
        }
        if (e % 2 == 0) {
            sum += tree[e];
            e--;
        }
        s /= 2;
        e /= 2;
    }

    return sum;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M >> K;

    int height = 0; // 트리 높이 구하기
    int len = N;
    while (len) {
        len /= 2;
        height++;
    }

    int treesize = int(pow(2, height + 1)); // 원본배열을 리프 노드로 두는 트리 크기
    int left = treesize / 2 - 1; // 원본 배열 저장 시작 인덱스
    tree.resize(treesize + 1);

    for (int i = left + 1; i <= left + N; i++) cin >> tree[i];
    maketree(treesize - 1);

    for (int i = 0; i < M + K; i++) {
        long a, s, e;
        cin >> a >> s >> e;

        if (a == 1) change(left + s, e);
        else if (a == 2) {
            s += left;
            e += left;
            cout << getsum(s, e) << endl;
        }
    }

}