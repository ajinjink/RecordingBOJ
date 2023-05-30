#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    double A, I;
    cin >> A >> I;

    double melody = 1;
    
    while (ceil(melody / A) < I) {
        melody++;
    }

    cout << melody;

}