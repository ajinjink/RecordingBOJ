#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int A, B;
        char comma;
        cin >> A >> comma >> B;
        cout << A + B << '\n';
    }
    

}