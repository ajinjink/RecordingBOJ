#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<long> A(N);
    vector<long> B(M);
    vector<long> C;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < M; i++) {
        cin >> B[i];
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int inda = 0, indb = 0;
    while (inda < N || indb < M) {
        if (inda == N) {
            for (indb; indb < M; indb++) {
                C.push_back(B[indb]);
            }
            
            break;
        }
        else if (indb == M) {
            for (inda; inda < N; inda++) {
                C.push_back(A[inda]);
            }
            
            break;
        }
        else if (A[inda] > B[indb]) {
            C.push_back(B[indb]);
            indb++;
        }
        else if (A[inda] <= B[indb]) {
            C.push_back(A[inda]);
            inda++;
        }
    }

    for (int i = 0; i < C.size(); i++) {
        cout << C[i] << ' ';
    }

}