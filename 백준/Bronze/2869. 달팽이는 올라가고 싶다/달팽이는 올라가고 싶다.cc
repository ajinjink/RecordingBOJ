#include <iostream>

using namespace std;

int main() {
    int A, B, V;
    cin >> A >> B >> V;
    int height = V - A;
    if (height % (A - B) == 0) {
        cout << height / (A - B) + 1;
    }
    else {
        cout << height / (A - B) + 2;
    }
}