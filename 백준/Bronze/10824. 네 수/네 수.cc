#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string A, B, C, D;
    cin >> A >> B >> C >> D;
    
    A += B;
    C += D;

    cout << stoll(A) + stoll(C);

}