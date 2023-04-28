#include <iostream>
using namespace std;

int Euclidean(int a, int b)
{
    int r = a % b;
    if (r == 0) {
      return b;
    }
    return Euclidean(b, r);
}



int main() {
    int A, B, gcd;
    cin >> A >> B;

    gcd = Euclidean(A, B);

    cout << gcd << '\n';

    cout << A * B / gcd;



}