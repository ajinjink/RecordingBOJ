#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> A;
vector<int> B;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, N, M, temp;
    
    cin >> T;
    
    for (int t = 0; t < T; t++) {
        cin >> N >> M;
        
        int count = 0;

        for (int i = 0; i < N; i++) {
            cin >> temp;
            A.push_back(temp);
        }
        for (int i = 0; i < M; i++) {
            cin >> temp;
            B.push_back(temp);
        }
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());

        for (int i = 0; i < N; i++) {
            int left = 0, right = M;
            while (left + 1 < right) {
                int mid = (left + right) / 2;
                if (B[mid] < A[i]) {
                    left = mid;
                }
                else {
                    right = mid;
                }                
            }
            count += left;
            if (A[i] > B[left]) {
                count++;
            }
        }
        
        cout << count << '\n';

        A.clear();
        B.clear();
    }
}

