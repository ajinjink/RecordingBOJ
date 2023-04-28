#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int N;
    cin >> N;

    for (int r = 0; r < N; r++) {
        int A[1001] = {0};
        int B[1001] = {0};
        
        int Acnt, Bcnt, temp;

        cin >> Acnt;
        for (int i = 0; i < Acnt; i++) {
            cin >> temp;
            A[temp]++;
        }

        cin >> Bcnt;
        for (int i = 0; i < Bcnt; i++) {
            cin >> temp;
            B[temp]++;
        }

        for (int i = 4; i > 0; i--) {
            if (A[i] > B[i]) {
                cout << "A" << '\n';
                break;
            }
            if (A[i] < B[i]) {
                cout << "B" << '\n';
                break;
            }
            if (A[i] == B[i] && i == 1) {
                cout << "D" << '\n';
            }
            
        }
    }



}