#include <iostream>
using namespace std;

int main() {
    int a, b, c, temp;
    cin >> a >> b >> c;
    do {
        if (a > c) {
            temp = a;
            a = c;
            c = temp;
        }
        if (b > c) {
            temp = b;
            b = c;
            c = temp;
        }
        if (a*a + b*b == c*c) {
            cout << "right" << '\n';
        }
        else {
            cout << "wrong" << '\n';
        }
        cin >> a >> b >> c;
    } while (!((a==0) && (b==0) && (c==0)));
        
}