#include <iostream>
using namespace std;

int main() {
    int A, B;

    cin >> A >> B;
    do {
        cout << A + B << '\n';
        cin >> A >> B;
    } while ((A!=0)&&(B!=0));
}