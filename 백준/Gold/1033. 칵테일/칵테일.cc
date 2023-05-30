#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

vector<tuple<int, int, int> > A[10]; // 인접 리스트
long lcm; // 최소공배수
bool visited[10];
long D[10]; // 각 노드 값 저장

long gcd(long a, long b) {
    if (b == 0) {
        return a;
    }
    else {
        return gcd(b, a % b);
    }
}

void DFS(int node) {
    visited[node] = true;

    for (tuple<int, int, int> i : A[node]) {
        int next = get<0>(i);
        if (!visited[next]) {
            D[next] = D[node] * get<2>(i) / get<1>(i); // 다음 노드값 = 현재 노드값 * 비율
            DFS(next);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    lcm = 1;

    for (int i = 0; i < N - 1; i++) {
        int a, b, p, q;
        cin >> a >> b >> p >> q;
        A[a].push_back(make_tuple(b, p, q));
        A[b].push_back(make_tuple(a, q, p));
        lcm *= (p * q / gcd(p, q));
    } // 인접 리스트 배열에 해당 에지 정보 저장

    D[0] = lcm; // 0번 노드에 최소 공배수 저장
    DFS(0);
    long mgcd = D[0]; // DFS를 통해 업데이트된 배열 D 값의 최대 공양수 계산
    // 배열 D의 각 값을 최대 공양수로 나누어서 정답 출력

    for (int i = 1; i < N; i++) {
        mgcd = gcd(mgcd, D[i]);
    }
    for (int i = 0; i < N; i++) {
        cout << D[i] / mgcd << ' ';
    }
}